#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/*
SnowData specification file
*/
class SnowData
{
private:
	string snow_date;
	double base_depth;
public:
	SnowData();
	SnowData(string _date, double _inches);
	void print();
	string getSnow_date();
	double getBase_depth();
	void setBase_depth(double);
	void setSnowDate(string);
};