/*Server for the Logmaster RFID Scanner using a BeagleBone Black.
Uses express to handle the server requests and responds with data from
the sqlite database created in the python program for the Logmaster. 
Runs as a daemon on start up and currently must be in the directory
"/home/root/Logmaster/Webserver" to function properly. */

//Importing required node modules
var fs = require("fs");
var child_process = require('child_process');
var http = require("http");
var express = require("express");
var sqlite3 = require("sqlite3");
var daemon = require('daemon')();
var bodyParser = require('body-parser');

//Setting up global database and port
var repository = "/home/root/Logmaster/Database-2013.db"
var exists = fs.existsSync(repository);
var db = new sqlite3.Database(repository);

var port = 8080;
		  
listen(port); //main process for this server

function listen(port)
{
	var app = express();
	app.use(bodyParser());
        
        //Links requests to their corresponding handler functions
	app.get('/', getClassLog);
	app.get('/class/:name',getClass);
	app.get('/class', getClass);
	app.get('/log/:tag',getLog);
	app.get('/log', getLog);
	app.get('/hours/:name',getHours);
	app.get('/hours', getHours);
	app.post('/input', handleInput);
	
	var server = http.createServer(app);
	server.listen(port);
}

function handleInput(req, res)
{
    //TODO: send over password in a more secure
    //format and use as an admin login
    res.send("You sent the name " + req.body.username);
}

function getClassLog(req, res)
{
	sql = "SELECT * FROM classLog"; //Default view
	sendData(res, "Tag,Name,hours", sql);
}

function getClass(req, res)
{
	var name = req.params.name;
	sql = "SELECT Tag,Name FROM class";
	if(name)
		sql += " WHERE name = ?"
	sendData(res,"Tag,Name", sql, name);
}

function getHours(req, res)
{
 	var name = req.params.name;
	sql = "SELECT Name,hours FROM classLog";
	if(name)
		sql += " WHERE name = ?"
	sendData(res, "Name,hours", sql, name);
}

function getLog(req, res)
{ 
    var tag = req.params.tag;
    sql = "SELECT tag,time FROM log";
    if(tag)
	sql += " WHERE tag = ?"
    sendData(res, "tag,time", sql, tag);
}

/*Queries the database using the given sql and params
and stores the data in a two dimensional array. This array
is then passed into sendTable for formatting.*/

//columns: a constant string expression with column titles separated by ','
function sendData(res, columns, sql, params)
{
	var splitColumns = columns.split(",");
	var nColumns = splitColumns.length;
	var storedData = new Array(nColumns);
	
	//creates two dimensional array.
	for(i = 0; i<nColumns; i++)
	{
		storedData[i] = new Array();
	}
	
	//makes column title the first element in each column.
	for(i in splitColumns)
	{
		storedData[i][0] = splitColumns[i];
	}
	
	//Fills array with data from sqlite database.
	db.serialize(function()
	{
	   var location = 1; //Second iterator for second dimension of array.
	   
	   /*sqlite3 command with two callback functions:
	   First one performs its operation on each row.
	   Second one executes once after all row are done being processed.*/
	   db.each(sql,params,
	   function(err,row)
	   {
	      for(i in splitColumns)
  	      {
		 if(row[splitColumns[i]])
		    storedData[i][location] = row[splitColumns[i]];
	      }
	      location++;
	    },
	    function(err,rows)
	    {
	      sendTable(rows, nColumns, storedData, res);
	    });
    });
}
/*Sends two dimensional array passed in as 'data' with
number of rows 'rows' and number of columns 'nColums'
to 'res' in the format of an html table*/

//TODO: Replace with angular and json so it 
//will be so much cleaner :)
	
function sendTable(rows, nColumns, data, res)
{
   //responseText holds html table as it gets created from the array.
   var responseText = '<table border = "1"><tr><td>';
   
   for(i = 0; i<=rows; i++)
   {
     for(i2 = 0; i2<nColumns; i2++)
     {
	if(nColumns - i2>1)
	   responseText += data[i2][i] + '</td><td>';
        else
           responseText += data[i2][i] + '</td>';
     }
    if(rows - i)
       responseText += '</tr><tr><td>';
    else
       responseText += '</tr>';
    }
    responseText += "</table>";
    
    fs.readFile('/home/root/Logmaster/Webserver/pageLayout.html', 
		'utf8', sendFile);
		
    //Injects table into layout file where appropriate.		
    function sendFile(err, file)
    {
	file = file.replace(/_INSERT_TABLE_/g, responseText);
	res.send(file);
    }
}

