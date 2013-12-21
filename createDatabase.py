import sqlite3
import os, sys
import serial
lib_path = os.path.abspath('Scanner')
sys.path.append(lib_path)
from RFID import*
#function(input from browser)


conn = sqlite3.connect("Database-2013.db")
c = conn.cursor()
c.execute('''CREATE TABLE IF NOT EXISTS class(Tag string, Name string)''')
name = raw_input("Enter your name ");
serial = serial.Serial("/dev/ttyUSB0", baudrate = 2400)
while name != "quit":
	print name + " scan your tag";
	rfidTag = rfidRead(serial);
	c.execute("INSERT INTO class VALUES(?,?)",[rfidTag,name]);
	name = raw_input("Enter your name ");#replace with input from browser

conn.commit();


