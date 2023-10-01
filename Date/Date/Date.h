#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d, int m, int y);

	void SetDay(int day);
	int GetDay();
	void SetMonth(int month);
	int GetMonth();
	void SetYear(int Year);
	int GetYear();

	Date& operator=(const Date& R);
	Date operator-(const Date& R) const;
	Date operator+(const Date& R) const;
	Date& operator-=(const Date& R);
	Date& operator-=(const int days);
	Date& operator+=(const Date& R);
	Date& operator+=(const int days);
friend ostream& operator<<(ostream& out, const Date& R);
friend istream& operator>>(istream& in, Date& R);
};

