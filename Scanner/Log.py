import datetime
import sqlite3


def log(string, database):
        conn = sqlite3.connect(database)
	c = conn.cursor()
	c.execute('''CREATE TABLE IF NOT EXISTS log
	          (
		  tag string,
		  time string
		  )
		  ''')
	time = datetime.datetime.now()

        c.execute('''INSERT INTO log (tag, time)
              VALUES (?, ?)''', (string, time))
        

	conn.commit()
	conn.close()
