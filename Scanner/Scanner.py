import serial
import time
import sys
from Log import log
from RFID import *
from Display import display
from threading import *
from LoggedIn import update_logged_in
from Hours import calculateHours
from Name import lookUpName

serial = serial.Serial("/dev/ttyUSB0", baudrate = 2400)
database = "../Database-2013.db"
def scan():
    rfidTag = rfidRead(serial)
    name = lookUpName(rfidTag, database)
    if name:
        log(rfidTag, database)
        hours = update_logged_in(rfidTag, database)
        display(rfidTag, hours, name, database)
    else:
	print "Unknown Tag or Noise"
while True:
    if activeCount() < 2:
	t = Timer(2, scan)
	t.start()
