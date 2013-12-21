import serial

def rfidEnable(serial):
	serial.setDTR(True)

def rfidDisable(serial):
	serial.setDTR(False)

def rfidFlush(serial):
	serial.read(serial.inWaiting())
	serial.flushInput()

def rfidDecode(str):
	tag = str.decode('utf8')
	tag = tag[1:11]
	return tag

def rfidRead(serial):
	rfidEnable(serial)
	rfidFlush(serial)
	rfidTag = rfidDecode(serial.read(12))
	rfidDisable(serial)
	return rfidTag
	
