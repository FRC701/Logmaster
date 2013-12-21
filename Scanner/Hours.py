from datetime import datetime

def createTable(conn):
   c = conn.cursor()
   c.execute('''CREATE TABLE IF NOT EXISTS hours
	     (
	      tag string,
	      hours real
	     )
	     ''')
def calculateHours(timeIn, timeOut):
    format = "%Y-%m-%d %H:%M:%S.%f"
    
    dateTimeIn = datetime.strptime(timeIn, format)
    timedelta = timeOut - dateTimeIn
 
    hours = timedelta.seconds/3600.0
    if hours > 0:
        return hours
    else: 
        return 0

def getCurrentHours(tag, conn):
    c = conn.cursor()
    c.execute("SELECT * FROM hours WHERE tag = ?", (tag,))
    row = c.fetchone()
    if row:
	return row[1]
    else:
	return 0

def updateValues(tag,hours, conn):
    c = conn.cursor()
    currentHours = getCurrentHours(tag, conn)
    if currentHours:
	newHours = currentHours + hours
	c.execute("UPDATE hours SET hours = ? WHERE tag = ?",
		   (newHours, tag,))
    else:
	c.execute("INSERT INTO hours VALUES (?, ?)",(tag, hours,))

def logHours(tag, timeIn, conn):
    createTable(conn)
    timeOut = datetime.now()
    hours = calculateHours(timeIn,timeOut)
    updateValues(tag, hours, conn)
    return hours
