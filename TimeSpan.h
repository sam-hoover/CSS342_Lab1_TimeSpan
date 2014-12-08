#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <climits>
#include <iostream>
using namespace std;

const int SECONDS_MAX = 59;
const int MINUTES_MAX = 59;
const int HOURS_MAX = INT_MAX - 1;
const int TIME_MIN = INT_MIN + 1;
const int NAUGHT = 0;
const int TIME_ARRAY_MAX = 2;
const int BUFFER = 256;
const double ROUNDER = 0.5;


class TimeSpan {
	friend ostream &operator<<(ostream &sout, const TimeSpan &that);
	friend istream &operator>>(istream &sin, TimeSpan &that);

	public:
		TimeSpan() : m_hours(NAUGHT), m_minutes(NAUGHT), m_seconds(NAUGHT) {}
		TimeSpan(double seconds);
		TimeSpan(double minutes, double seconds);
		TimeSpan(double hours, double minutes, double seconds);
		TimeSpan(TimeSpan const &that);

		int getHours() const {return(m_hours);}
		int getMinutes() const {return(m_minutes);}
		int getSeconds() const {return(m_seconds);}

		bool operator==(TimeSpan const &that);
		bool operator!=(TimeSpan const &that);
		TimeSpan operator-() const;
		TimeSpan operator+(TimeSpan &that);
		TimeSpan operator-(TimeSpan &that);
		TimeSpan operator+=(TimeSpan &that);
		TimeSpan operator-=(TimeSpan &that);
		
	protected:
		void setHours(int hours);
		void setMinutes(int mins);
		void setSeconds(int secs);

	private:
		int m_hours;
		int m_minutes;
		int m_seconds;	
};

int parseToken(string token);

#endif
