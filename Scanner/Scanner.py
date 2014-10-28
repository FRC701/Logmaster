import serial
import time
import sys

from threading import *

from RFID import *
from Name import lookUpName
from Log import log
from LoggedIn import update_logged_in
from Display import display

serial = serial.Serial("/dev/ttyUSB0", baudrate = 2400)
database = "../Database-2013.db"

#Scan is the main process for the RFID Scanner. 
#It is run every two seconds after it exits through the Timer t.
#It puts together the code from all other imported files. 

def scan():
    rfidTag = rfidRead(serial) #From RFID.py returns tag scanned as a string
    name = lookUpName(rfidTag, database) #Returns 0 if no match in database.
    if name:
        log(rfidTag, database) #Simply adds log file with time and tag to database.
        hours = update_logged_in(rfidTag, database)#Logs in/out person and updates hours if needed.
        display(rfidTag, hours, name, database)#Runs BeagleDisplay1 as subprocess and pipes over data.
    else:
	print "Unknown Tag or Noise"
while True:
    if activeCount() < 2:     #The display subprocess makes this 2 when scan is running and 1 when scan exits.
	t = Timer(2, scan)    #Run every two seconds. Gives person time to remove tag before double read.
	t.start()
