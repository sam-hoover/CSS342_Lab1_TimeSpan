#include "TimeSpan.h"
#include <stdlib.h>
#include <cmath>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

TimeSpan::TimeSpan(double seconds) {
	setHours(NAUGHT);
	setMinutes(NAUGHT);
	setSeconds(static_cast<int>(seconds));
}

TimeSpan::TimeSpan(double minutes, double seconds) {
	setHours(NAUGHT);
	setMinutes(static_cast<int>(minutes));
	setSeconds(static_cast<int>(seconds));
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds) {
	setHours(static_cast<int>(hours));
	setMinutes(static_cast<int>(minutes));
	setSeconds(static_cast<int>(seconds));
}

TimeSpan::TimeSpan(TimeSpan const &that) {
	setHours(that.m_hours);
	setMinutes(that.m_minutes);
	setSeconds(that.m_seconds);
	//*this = TimeSpan(that.getHours(), that.getMinutes(), that.getSeconds());
}

bool TimeSpan::operator==(TimeSpan const &that) {
	if(this->getHours() == that.getHours() && this->getMinutes() == that.getMinutes() && this->getSeconds() == that.getSeconds()) {
		return(true);
	}
	return(false);
}

bool TimeSpan::operator!=(TimeSpan const &that) {
	if(*this == that) {
		return(false);
	}
	return(true);
}

TimeSpan TimeSpan::operator-() const {
	TimeSpan temp;
	temp.setHours(-this->getHours());
	temp.setMinutes(-this->getMinutes());
	temp.setSeconds(-this->getSeconds());
	return(temp);
}

TimeSpan TimeSpan::operator+(TimeSpan &that) {
	TimeSpan temp;
	temp.setHours(this->getHours() + that.getHours());
	temp.setMinutes(this->getMinutes() + that.getMinutes());
	temp.setSeconds(this->getSeconds() + that.getSeconds());
	return(temp);
}

TimeSpan TimeSpan::operator-(TimeSpan &that) {
	TimeSpan temp;
	temp.setHours(this->getHours() - that.getHours());
	temp.setMinutes(this->getMinutes() - that.getMinutes());
	temp.setSeconds(this->getSeconds() - that.getSeconds());
	return(temp);
}

TimeSpan TimeSpan::operator+=(TimeSpan &that) {
	*this = *this + that;
	return(*this);
}

TimeSpan TimeSpan::operator-=(TimeSpan &that) {
	*this = *this - that;
	return(*this);
}

ostream &operator<<(ostream &sout, const TimeSpan &that) {
	sout << "Hours: " << that.getHours() << " Minutes: " << that.getMinutes() << " Seconds: " << that.getSeconds();
	return(sout);
}

istream &operator>>(istream &sin, TimeSpan &that) {
	string token;
	int i = 0;
	int times[3] = {0, 0, 0};
	while(sin.peek() != '\n' && i <= TIME_ARRAY_MAX) {
		token = sin.get();
		char ch = sin.peek();
		while(ch != ' ' && ch != '\n') {
			token += sin.get();
			ch = sin.peek();
		}

		try {
			times[i] = parseToken(token);
			i++;
		} catch(const invalid_argument) {
			i++;
		} catch(const exception) {
			i++;
		}
	}
	that.setHours(times[0]);
	that.setMinutes(times[1]);
	that.setSeconds(times[2]);
	return(sin);
}

int parseToken(string token) {
	int parsedToken = 0;
	char str[BUFFER];
	char* end;
	for(unsigned i = 0; i < token.length() + 1; i++) {
		str[i] = token[i];
	}
	double num = strtod(str, &end);
	parsedToken = static_cast<int>(num);
	return(parsedToken);
}

void TimeSpan::setHours(int hours)
{
	if(hours >= HOURS_MAX) {
		m_hours = HOURS_MAX;
	} else if(hours <= TIME_MIN) {
		m_hours = TIME_MIN;
	} else {
		m_hours = hours;
	}
}

void TimeSpan::setMinutes(int minutes) {
	while(minutes < NAUGHT) {
		if(m_hours > NAUGHT) {
			setHours(m_hours - 1);
			minutes += (MINUTES_MAX + 1);
		} else {
			break;
		}
	}

	if(abs(minutes) > MINUTES_MAX) {
		setHours(m_hours + (static_cast<int>(minutes / (MINUTES_MAX + 1))));
		minutes %= (MINUTES_MAX + 1);
	} 
	m_minutes = minutes;
}

void TimeSpan::setSeconds(int seconds) {
	while(seconds < NAUGHT) {
		if(m_minutes <= NAUGHT) {
			if(m_hours > NAUGHT) {
				setHours(m_hours - 1);
				m_minutes += 60;
			} else {
				break;
			}
		}
		m_minutes--;
		seconds += 60;
	}

	if(abs(seconds) > SECONDS_MAX) {
		setMinutes(m_minutes + (static_cast<int>(seconds / (SECONDS_MAX + 1))));
		seconds %= (SECONDS_MAX + 1);
	}
	m_seconds = seconds;
}


//void TimeSpan::setMinutes(int minutes) {
//	while(minutes < NAUGHT) {
//		setHours(m_hours - 1);
//		minutes += 60;
//	}
//
//	if(abs(minutes) > MINUTES_MAX) {
//		setHours(m_hours + (static_cast<int>(minutes / (MINUTES_MAX + 1))));
//		minutes %= (MINUTES_MAX + 1);
//	} 
//	m_minutes = minutes;
//}

//void TimeSpan::setSeconds(int seconds) {
//	while(seconds < NAUGHT) {
//		if(m_minutes <= NAUGHT) {
//			setHours(m_hours - 1);
//			m_minutes += 60;
//		}
//		m_minutes--;
//		seconds += 60;
//	}
//	if(abs(seconds) > SECONDS_MAX) {
//		setMinutes(m_minutes + (static_cast<int>(seconds / (SECONDS_MAX + 1))));
//		seconds %= (SECONDS_MAX + 1);
//	}
//	m_seconds = seconds;
//}

