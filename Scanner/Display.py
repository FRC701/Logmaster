import datetime 
from Hours import getCurrentHours
import sqlite3
import subprocess

execString = "../BeagleDisplay1"

#Executes display program as a subprocess using its stdin and stdout as pipes
p = subprocess.Popen([execString,"-qws"],
                      stdin=subprocess.PIPE,
                      stdout=subprocess.PIPE)
                      
#Sends formatted string to display file
def sendMessage(message):
	childIn = p.stdin
	childIn.flush()
	childIn.write(message)

#Creates a formatted string containing all the info to be displayed.
#Calls sendMessage on this formatted string.
def display(string, hours, name, database):
	conn = sqlite3.connect(database)
	output = string + " " + name + " "
	if name:
	    if hours:
		output += "Out "
		output +=  str(hours) + " "
	    else:
		output += "In 0 "
	    sendMessage(output)	    	
	else:
	    print "Unknown tag. Please enter into database first"
	
