#include "ClassTime.h"

Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }


void Time::setHours(double newHours) { hours = newHours; }
void Time::setMinutes(double newMinutes) { minutes = newMinutes; }
void Time::setSeconds(double newSeconds) { seconds = newSeconds; }

Time Time::timeUntil(const Time& other) const {
	int h_diff = other.hours - hours;
	int m_diff = other.minutes - minutes;
	int s_diff = other.seconds - seconds;
	if (s_diff < 0) {
		s_diff += 60;
		m_diff--;
	}

	if (m_diff < 0) {
		m_diff += 60;
		h_diff--;
	}

	if (h_diff < 0) {
		h_diff += 24;
	}

	return Time(h_diff, m_diff, s_diff);
}


Time Time::operator ++() {
	minutes++;
	if (minutes >= 60) {
		hours++;
		minutes = 0;
		if (hours >= 24) {
			hours = 0;
		}
	}
	return *this;
}

Time Time::operator ++(int value) {
	Time temp(*this);
	seconds++;
	if (seconds >= 60) {
		minutes++;
		seconds = 0;
		if (minutes >= 60) {
			hours++;
			minutes = 0;
			if (hours >= 24) {
				hours = 0;
			}
		}
	}
	return temp;
}

bool Time::operator >(const Time& other) const {
	if (hours > other.hours) {
		return true;
	}
	else if (hours < other.hours) {
		return false;
	}
	else {
		if (minutes > other.minutes) {
			return true;
		}
		else if (minutes < other.minutes) {
			return false;
		}
		else {
			return seconds > other.seconds;
		}
	}
}
