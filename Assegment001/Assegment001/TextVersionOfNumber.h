
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class TextVersionOfNumber
{

private:
	double amount;
public:
	TextVersionOfNumber();
	TextVersionOfNumber( double _amount);
	string getTextVersionOfNumber();
	void setAmount(double);

};