#ifndef _TIME
#define _TIME

class Time
{
private:
	int getSeconds();
public:
	int second;
	int minute;
	int hour;
	
	Time();
	Time(int seconds);
	Time(int h, int m, int s);
	Time(const Time& t);
	
	bool operator==(Time& t);
	bool operator>=(Time& t);
	bool operator<=(Time& t);
	bool operator>(Time& t);
	bool operator<(Time& t);
	
	void operator=(Time& t);
	
	~Time();
};

#endif