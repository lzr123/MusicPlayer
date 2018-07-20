#include "Time.h"

Time::Time()
{
	second = 0;
	minute = 0;
	hour = 0;
}

Time::Time(int seconds)
{
	second = seconds % 60;
	minute = (seconds / 60) % 60;
	hour = (seconds / 60) / 60;
}

Time::Time(int h, int m, int s)
{
	int seconds = h * 3600 + m * 60 + s;
	Time(seconds);
}

Time:Time(const Time& t)
{
	second = t.second;
	minute = t.minute;
	hour = t.hour;
}

int Time::getSeconds()
{
	return hour * 3600 + minute * 60 + second;
}	

bool Time::operator==(Time& t)
{
	if(getSeconds() == t.getSeconds())
		return true;
	else
		return false;
}

bool Time::operator>=(Time& t)
{
	if(getSeconds() >= t.getSeconds())
		return true;
	else
		return false;
}

bool Time::operator<=(Time& t)
{
	if(getSeconds() <= t.getSeconds())
		return true;
	else
		return false;
}

bool Time::operator>(Time& t)
{
	if(getSeconds() > t.getSeconds())
		return true;
	else
		return false;
}

bool Time::operator<(Time& t)
{
	if(getSecons() < t.getSeconds())
		return true;
	else
		return false;
}

void Time::operator=(Time& t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
}

Time::~Time()
{
	
}















