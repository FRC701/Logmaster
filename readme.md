# LogMaster

The LogMaster uses three processe a python Scanner program, a node 
javascript Webserver, and a display created in QT.
These programs rely on a sqlite database contained in the project directory.

The database must be created first by calling 'python createDatabase.py' which 
will prompt for names. Input a name first then scan the corresponding tag
for that person. When finished input 'quit' as the name. The database also 
does not currently have its default view properly setup. To get this setup simply
use the command 'sqlite3 Database-2014.db' and input the following sql command:

CREATE VIEW classLog AS SELECT class.Tag, class.Name, hours.hours FROM class, 
hours WHERE class.Tag = hours.tag ORDER BY class.Name;

To get the webserver to start up on boot you must properly setup the RFIDWebserver.service.
This is done by placing RFIDWebserver.sh in the path /usr/bin. The RFIDWebserver.service
must be placed in the path /lib/systemd/system. Then execute the following 
command: 'systemctl enable RFIDWebserver.service'. Reset and the server should start up.



