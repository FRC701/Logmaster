import sqlite3
import datetime
from Hours import logHours

#The scanner creates an entry for each tag that it sees at first in the table loggedIn.
#This tag is then logged in. When it sees the tag again it deletes the entry logging them out.

def is_logged_in(string, conn):
    c = conn.cursor()
    
    rows = c.execute("SELECT * FROM loggedIn")

    for row in rows:
        if string == row[0]:
             conn.commit()
             return True
    
    # This tag is not in table loggedIn. 
    conn.commit()
    return False

def log_in(string, conn):
    c = conn.cursor()
    time = datetime.datetime.now()
    c.execute('''INSERT INTO loggedIn VALUES (?, ?)''', (string,time,))
    conn.commit()

def log_out(tag, conn):
    c = conn.cursor()
    c.execute('''SELECT time FROM loggedIn
 			 WHERE tag = ?
		     ''', (tag,))
    row = c.fetchone()
    timeIn = row[0]
    
    #deletes entry logging them out.
    c.execute('''DELETE FROM loggedIn
                 WHERE tag = ?''',(tag,))
   
    #update hours as they leave.
    hours = logHours(tag, timeIn, conn)
    
    #pass hours up. Eventual destination: display().
    return hours
    conn.commit()

def update_logged_in(string, database):
    conn = sqlite3.connect(database)
    c = conn.cursor()

    # Holds the tag of each person who is currently logged in.
    c.execute('''CREATE TABLE IF NOT EXISTS loggedIn
	      (
		tag string,
                time string
	      )
	      ''')

    #Returns hours so scanner will be able to pass them into display.
    if is_logged_in(string, conn):
        hours = log_out(string, conn)
	returnVal = hours
	
    #0 value lets scanner now they are being logged in.
    else:
        log_in(string, conn)
	returnVal = 0

    conn.commit()
    conn.close()

    return returnVal	

