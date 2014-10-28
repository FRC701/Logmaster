#include "Worker.h"

#include <iostream>
#include <string>

using namespace std;
void Worker::doWork()
{
   string tag, firstName, lastName, logStatus, name, hours;
   while(true)
   {
        string status = "Logging ";
	cin>>tag>>firstName>>lastName>>logStatus>>hours;
        status += logStatus;
        name = firstName + lastName;
        const char* charTag = tag.c_str();
        const char* charName = name.c_str();
        const char* charStatus = status.c_str();
        const char* charHours = hours.c_str();

        qTag = QString(charTag);
        qName = QString(charName);
        qStatus = QString(charStatus);
        qHours = QString(charHours);

        emit finished();
   }
}
