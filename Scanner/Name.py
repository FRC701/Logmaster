import sqlite3

def lookUpName(str, database):
    conn = sqlite3.connect(database)
    c = conn.cursor()
    c.execute("SELECT Name FROM class WHERE Tag = ?",
		(str,))
    row = c.fetchone()
    if row:
	return row[0]
    else:
	return 0
