#pragma once
#include <time.h>
#include <iostream>

class CTime {
private:
	time_t date;

public:
	//Defaut Constructor
	CTime();
	//Constructor
	CTime(int year, int month, int day, int hour, int minute, int seconds);
	//Constructor por copia
	CTime(const CTime& c);
	//Destructor
	~CTime();

	//Acceso a date
	time_t getDate();
};
