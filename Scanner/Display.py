import datetime
from Hours import getCurrentHours
import sqlite3

def display(str, hours, name, database):
	conn = sqlite3.connect(database)
	if name:
	    if hours:
	        print "Goodbye " + name
	        print "Earned Hours: "
	        print hours
	    else:
	        print "Welcome " + name
	    print "Total Hours: "
	    print getCurrentHours(str, conn)
	    print datetime.datetime.now()
	else:
	    print "Unknown tag. Please enter into database first"
	
