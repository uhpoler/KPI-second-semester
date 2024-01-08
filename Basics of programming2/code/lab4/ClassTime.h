#pragma once
#include <iostream>
#include <cmath>


using namespace std;

class Time {
	int hours, minutes, seconds;
public:
	Time();
	Time(int hours, int minutes, int seconds);
	Time(const Time& other);

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;
	

	void setHours(double newHours);
	void setMinutes(double newMinutes);
	void setSeconds(double newSeconds);
	
	// Метод для обчислення часу, що залишився до заданого моменту
	Time timeUntil(const Time& other) const;


	Time operator ++();
	Time operator ++(int value);
	bool operator>(const Time& other) const;




};

