// Assegment001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<sstream>
using namespace std;
#include "TextVersionOfNumber.h"

int main()
{
	TextVersionOfNumber checkAmount;
	double testAmounts[] = { 0 , .01 , .25 , 12.12 , 12.45 , 19 , 19.02 ,
	19.45 , 20 , 20.65 , 34 , 56.78 , 100.21 , 109.05 ,
	119.78 , 450 , 678.90 , 1000 , 1011 ,
	1011.11 , 1009.45 , 1056 ,
	1234.15 , 1567.98 , 9999 , 9999.99 };
	cout << setprecision(2) << fixed << left;		
	for (auto an_amount : testAmounts)
	{ 
		checkAmount.setAmount(an_amount);
		cout <<" $" << setw(10) << an_amount;
		cout << setw(20) << checkAmount.getTextVersionOfNumber() << endl;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
