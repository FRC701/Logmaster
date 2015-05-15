# Logmaster

To setup the BeagleBone Black with all the required libraries and modules follow the instructions
located in the google drive file Logmaster BeagleBone Setup found at:

https://docs.google.com/document/d/1Y4MnArsMk4cDz4v59kP5t9tCZwnDFomx2bUn7sPrNNw/edit

The Logmaster uses three processe a python Scanner program, a node 
javascript Webserver, and a display created in QT.
These programs rely on a sqlite database contained in the project directory.

The database must be created first by calling:
```
python createDatabase.py 
```
This will prompt for names. Input a name first then scan the corresponding tag
for that person. When finished input 'quit'. The database also does not currently have its default view properly setup. 
To get this setup simply use the command 
```
sqlite3 Database-2014.db 
```
and inputing the following SQL command:

```
CREATE VIEW classLog AS SELECT class.Tag, class.Name, hours.hours FROM class, 
hours WHERE class.Tag = hours.tag ORDER BY class.Name;
```

To get the webserver to start up on boot you must properly setup the RFIDWebserver.service.
This is done by placing RFIDWebserver.sh in the path /usr/bin. The RFIDWebserver.service
must be placed in the path /lib/systemd/system. Then execute the following 
command:
```
systemctl enable RFIDWebserver.service 
```
Reset and the server should start up.

#### Known Issues:

1. Python process does not start up on boot
2. Python process is not easily killed
3. NTP will not work on school server
4. ttyUSB0 sometimes is not created requiring reboot.
5. No way to create database in webserver. (Database must exist for webserver to run in first place)
6. Logs are not editable through webserver. (Logs Must be edited through command line sqlite)
