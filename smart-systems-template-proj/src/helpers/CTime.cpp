#include "CTime.h"
#include <time.h>
#include <iostream>

using namespace std;

//Constructors
CTime::CTime() {
	date = time(0); // get the current datetime
	struct tm* timeinfo; // structure to manage dates
	timeinfo = localtime(&date);
	timeinfo->tm_mon = 0; // month: January
	timeinfo->tm_mday = 9; // day of the month: 9
	timeinfo->tm_year = 2015 - 1900; // year 2015
	timeinfo->tm_hour = 0; // hour 0
	timeinfo->tm_min = 0;
	timeinfo->tm_sec = 0;
	date = mktime(timeinfo); // get the new date
	//cout << "Default creation" << endl;
}

CTime::CTime(int year, int month, int day, int hour, int minute, int seconds) {
	date = time(0); // get the current datetime
	struct tm* timeinfo; // structure to manage dates
	timeinfo = localtime(&date);
	timeinfo->tm_mon = month; // month: January
	timeinfo->tm_mday = day; // day of the month: 9
	timeinfo->tm_year = year - 1900; // year 2015
	timeinfo->tm_hour = hour; // hour 0
	timeinfo->tm_min = minute;
	timeinfo->tm_sec = seconds;
	date = mktime(timeinfo); // get the new date
	//cout << "I have been created with date = " << date << endl;
}

CTime::CTime(const CTime& c) {
	*this = c;
	//cout << "I have been created with date = " << c.date << endl;
}

//Destructor
CTime::~CTime() {
	//cout << "I have been deleted date = " << date << endl;
}

//Función para acceder a date
time_t CTime::getDate() {
	return date;
}

