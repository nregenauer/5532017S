//Nicole Regenauer
//Hw4a: JulianDate
//I pledge my honor that I have abided by the Stevens Honor System
//All formulas in this code were obtained from Wikipedia
//https://en.wikipedia.org/wiki/Julian_day

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;


class JulianDate {
private:
	long double jday;
	long double jtime;
public:
	JulianDate(int year=0, int month=0, int day=0, int hour=0, int min=0, int sec=0) {
		long double a=(14-month)/12;
		long double y=year+4800-a;
		long double m=month+12*a-3;
		jday = day + floor((153*m+2)/5) +365*y +floor((y/4)) -floor((y/100)) +floor((y/400))-32045;
		jtime = double(hour)/24.0 + double(min)/1440.0+ double(sec)/86400.0;
		jday=jday+jtime;

	}
	void timeconv (int& h, int& m, int& s) const{
			long double jay = jday;
			jay = jay - int(jay);
			long double hrs = jay * 24;
			h = ceil(hrs);
			long double mts = hrs - h;
			mts = mts * double(60.0);
			m = ceil(mts);
			long double scs = mts - m;
			scs = scs * double(60.0);
			s=int(scs);
	}

	friend double operator - (JulianDate j1, JulianDate j2){
		int intermed = int(j1.jday) - int(j2.jday);
		long double fract = (j1.jday-int(j1.jday)) - (j2.jday-int(j2.jday));
		long double result = double(intermed) + fract;
		return result;
	}

	friend JulianDate operator + (JulianDate j1, double d){
			long double n = j1.jday + double(d);
			int year,month,day,hours,mins,secs;
			j1.convGregDay(n,year,month,day);
			j1.timeconv(hours,mins,secs);
			return JulianDate(year,month,day,hours,mins,secs);
	}

	friend ostream& operator << (ostream& s, JulianDate j){
		s << j.jday << endl;
		return s;
	}
	void convGregDay(long double jday, int& year, int& month, int& day) const{
				long int f = floor(jday) + 1401 + (((4*floor(jday)+274277)/146097)*3)/4 -38;
				long int e = 4*f + 3;
				long int g = (e%1461)/4;
				long int h= 5*g+2;
				long int D = (h%153)/5 +1;
				long int M = (h/153+2)%12 + 1;
				long int Y = floor(e/1461) - 4716 + floor((14 - M)/12);
				year = int(Y);
				month = M;
				day = D;
				}

	int getYear() const{
		int year=0,month=0,day=0;
		convGregDay(year,month,day);
		return year;
	}

	int getMonth() const{
		int year,month,day;
		convGregDay(year,month,day);
		return month;
	}

	int getDay() const{
		int year,month,day;
		convGregDay(year,month,day);
		return day;
	}
	int getHour() const{
		int hour,min,sec;
		timeconv(hour,min,sec);
		return hour;
	}
	int getMin() const{
		int hour,min,sec;
		timeconv(hour,min,sec);
		return min;
	}
	int getSec() const{
		int hour,min,sec;
		timeconv(hour,min,sec);
		return sec;
	}

	void convGregDay(int& year, int& month, int& day) const{
				long int f = floor(this->jday) + 1401 + (((4*floor(this->jday)+274277)/146097)*3)/4 -38;
				long int e = 4*f + 3;
				long int g = (e%1461)/4;
				long int h= 5*g+2;
				long int D = (h%153)/5 +1;
				long int M = (h/153+2)%12 + 1;
				long int Y = (e/1461) - 4716 +(12-M+2)/12;
				year = Y;
				month = M;
				day = D;

			}
};
	int main() {
		const JulianDate d1(2017, 2, 13, 20, 00, 00);
		const JulianDate d1b(2017, 2, 13, 22, 00, 00);

		cout << d1b - d1 << '\n'; // 2 hours = 2/24 day

		const JulianDate tomorrow = d1 + 1;
		cout << tomorrow; // 2017 2 14 20 00 00
		cout << tomorrow - d1 << '\n';
		// hh:mm:ss  20/24  20/24.0
		const JulianDate d2(2017, 2, 19); // 00:00:00
	  const JulianDate d3 = d2 + 3; // what is it 3 days later?
		double days   = d3 - d1;

		int year = d3.getYear();
		int month = d3.getMonth();
		int day = d3.getDay();
		int hour = d3.getHour();
		int min = d3.getMin();
		int sec = d3.getSec();
		cout << d1 << '\n';
		cout << d2 << '\n';
		cout << d3 << '\n';
		cout << year << " " << month << " " << day <<
			hour << " " << min << " " << sec << '\n';
		// Not every operation makes sense!
		//	JulianDate d5 = d3 * d1;
		JulianDate torture(2017, 2, 27); // 00:00:00
		for (int i = 0; i < 3; i++) {
			cout << torture.getYear() << " " << torture.getMonth() << " " << torture.getDay() << '\n';
			torture = torture + 1;
		}
	}
