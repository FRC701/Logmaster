var fs = require("fs");
var child_process = require('child_process');
var http = require("http");
var winston = require('winston');
var express = require("express");
var sqlite3 = require("sqlite3");
var socketio = require('socket.io');
var daemon = require('daemon')();
var repository = "/home/root/LogMaster1.0/Database-2013.db"
var exists = fs.existsSync(repository);
var db = new sqlite3.Database(repository);

var port = 8080;
		  
listen(port);
function listen(port)
{
	var app = express();
	app.get('/', getClassLog);
	app.get('/class/:name',getClass);
	app.get('/class', getClass);
	app.get('/log/:tag',getLog);
	app.get('/log', getLog);
	app.get('/hours/:name',getHours);
	app.get('/hours', getHours);
	var server = http.createServer(app);
	server.listen(port);
}

function getClassLog(req, res)
{
	sql = "SELECT * FROM classLog";
	sendData(res, "Tag,Name,hours", sql);
}
function getClass(req, res)
{
	var name = req.params.name;
	sql = "SELECT Tag,Name FROM class";
	if(name)
		sql += " WHERE name = ?"
	console.log(sql);
	sendData(res,"Tag,Name", sql, name);
}
function getHours(req, res)
{
 	var name = req.params.name;
	sql = "SELECT Name,hours FROM classLog";
	if(name)
		sql += " WHERE name = ?"
	console.log(sql);
	sendData(res, "Name,hours", sql, name);
}
function getLog(req, res)
{ 
    var tag = req.params.tag;
    sql = "SELECT tag,time FROM log";
    if(tag)
	sql += " WHERE tag = ?"
    console.log(sql);	
    sendData(res, "tag,time", sql, tag);
}
	
function sendData(res, columns, sql, params)
{
	var splitColumns = columns.split(",");
	var nColumns = splitColumns.length;
	var storedData = new Array(nColumns);
	for(i = 0; i<nColumns; i++)
	{
		storedData[i] = new Array();
	}
	for(i in splitColumns)
	{
		storedData[i][0] = splitColumns[i];
	}
	db.serialize(function()
	{
	   var location = 1;
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
	      console.log(nColumns); 
	      sendTable(rows, nColumns, storedData, res);
	    });
    });
}

	
function sendTable(rows, nColumns, data, res)
{
   var responseText = '<html><body><table border = "1"><tr><td>';
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
    responseText += "</table></body></html>";
    fs.readFile('/home/root/LogMaster1.0/Webserver/pageLayout.html', 
		'utf8', sendFile);
    function sendFile(err, file)
    {
	file = file.replace(/_INSERT_TABLE_/g, responseText);
	res.send(file);
    }
}

