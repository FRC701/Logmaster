import datetime 
from Hours import getCurrentHours
import sqlite3
import subprocess

execString = "../../BeagleDisplay1"
p = subprocess.Popen([execString,"-qws"],
                      stdin=subprocess.PIPE,
                      stdout=subprocess.PIPE)

def sendMessage(message):
	childIn = p.stdin
	childIn.flush()
	childIn.write(message)

def display(string, hours, name, database):
	conn = sqlite3.connect(database)
	output = string + " " + name + " "
	if name:
	    if hours:
	        print "Goodbye " + name
		output += "Out "
	        print "Earned Hours: "
	        print hours
		output +=  str(hours) +" "
	    else:
	        print "Welcome " + name
		output += "In 0 "
	    print "Total Hours: "
	    print getCurrentHours(string, conn)
	    print datetime.datetime.now()
	    sendMessage(output)	    	
	else:
	    print "Unknown tag. Please enter into database first"
	
