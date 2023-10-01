#include <iostream>
#include <cmath>
#include "Date.h"

const int MONTHS[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date() {
	day = 1;
	month = 1;
	year = 2023;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

void Date::SetDay(int day) { this->day = day; }
int Date::GetDay() { return day;  }

void Date::SetMonth(int month) { this->month = month; }
int Date::GetMonth() { return month;  }

void Date::SetYear(int year) { this->year = year; }
int Date::GetYear() { return year;  }

Date& Date::operator=(const Date& R) {
	day = R.day;
	month = R.month;
	year = R.year;
	return *this;
}

Date Date::operator-(const Date& R) const{
	int days1 = 0, days2 = 0;
	days1 += day;
	days2 += R.day;

	for (int i = 0; i < month; i++)
		 days1 += MONTHS[i];
	for (int i = 0; i < R.month; i++)
		days2 += MONTHS[i];

	for (int i = 0; i < year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			days1 += 366;
		else
			days1 += 365;
	}
	for (int i = 0; i < R.year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			days2 += 366;
		else
			days2 += 365;
	}
	Date resultDate;
	resultDate.day = days1 - days2;
	resultDate.month = 0;
	resultDate.year = 0;
	return resultDate;
}

Date Date::operator+(const Date& R) const {
	int days1 = 0, days2 = 0;
	days1 += day;
	days2 += R.day;

	for (int i = 0; i < month; i++)
		days1 += MONTHS[i];
	for (int i = 0; i < R.month; i++)
		days2 += MONTHS[i];

	for (int i = 0; i < year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			days1 += 366;
		else
			days1 += 365;
	}
	for (int i = 0; i < R.year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			days2 += 366;
		else
			days2 += 365;
	}
	Date resultDate;
	resultDate.day = days1 + days2;
	resultDate.month = 0;
	resultDate.year = 0;
	return resultDate;
}

Date& Date::operator-=(const Date& R) {
	day -= R.day;

	for (int i = 0; i < month; i++)
		day -= MONTHS[i];
	month = 0;
	for (int i = 0; i < R.month; i++)
		day -= MONTHS[i];

	for (int i = 0; i < year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			day -= 366;
		else
			day -= 365;
	}
	year = 0;
	for (int i = 0; i < R.year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			day -= 366;
		else
			day -= 365;
	}
	return *this;
}


Date& Date::operator+=(const Date& R){
	day += R.day;

	for (int i = 0; i < month; i++)
		day += MONTHS[i];
	month = 0;
	for (int i = 0; i < R.month; i++)
		day += MONTHS[i];

	for (int i = 0; i < year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			day += 366;
		else
			day += 365;
	}
	year = 0;
	for (int i = 0; i < R.year; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			day += 366;
		else
			day += 365;
	}
	return *this;
}


Date& Date::operator-=(int days){
	day -= days;
	while (true) {
		if (day <= 0) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (month == 2)
					day += 29;
			}
			else
				day += MONTHS[month - 1];
			month--;
			if (month < 1) {
				month += 12;
				year--;
			}
		}
		else
			break;
	}
	return *this;
}

Date& Date::operator+=(int days) {
	day += days;
	while (true) {
		if (day > MONTHS[month - 1]) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (month == 2)
					day -= 29;
			}
			else
				day -= MONTHS[month - 1];
			month++;
			if (month > 12) {
				month -= 12;
				year++;
			}
		}
		else
			break;
	}
	return *this;
}

ostream& operator<<(ostream& out,const Date& R) {
	cout << R.day << '/' << R.month << '/' << R.year << endl;
	return out;
}

istream& operator>>(istream& in, Date& R) {
	cout << "Enter d/m/y: ";
	in >> R.day >> R.month >> R.year;
	return in;
}


