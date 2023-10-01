#include "TextVersionOfNumber.h"

/*
	Class default constructor
	Sets default values for class private variables
*/
TextVersionOfNumber::TextVersionOfNumber()
{
	amount = 0.0;
}
/*
	Overloaded constructor
	Parameters used to populate class private variables via set functions
*/
TextVersionOfNumber::TextVersionOfNumber(double _amount)
{
	amount = _amount;
}
/*
	mutator function for amount.
	ensures that amount is not set to a negative value
*/
void TextVersionOfNumber::setAmount(double _amount)
{
		amount = _amount;
}

/*
*/
string TextVersionOfNumber::getTextVersionOfNumber()
{
	string printOut = "";

	string one_19[] = { "" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" ,
 "nine" , "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" ,
 "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen" };

	string twenty_90[] = { "" , "" , "twenty" , "thirty" , "forty" , "fifty" , "sixty" , "seventy" ,
	 "eighty", "ninety" };


	int int_cents;
	int_cents = amount * 100;
	int_cents = int_cents % 100;
	
	if (amount < 1)
		printOut = " zero dollars and "+to_string( int_cents) + " Cents";
	else if (amount < 20)
		printOut = one_19[(int)amount] + "  dollar and " + to_string(int_cents) + " Cents";
	else if (amount < 100)
	{
		int rdight = ((int)amount % 10);
		int Ldight = (int)amount / 10;
		printOut = twenty_90[Ldight] + " " + one_19[rdight] + " dollars and " + to_string(int_cents) + " Cents";
	}
	else if (amount < 1000)
	{
		int rdight = ((int)amount % 100);
		int Ldight = (int)amount / 100;
		int num_val,p1,p2;

		if (rdight>=20 && rdight<=99) {
			num_val = rdight;
			 p1 = num_val % 10;
			 p2 = num_val / 10;
			printOut = one_19[Ldight] + " hundred and " + twenty_90[p2] + " " + one_19[p1] + "  dollars and " + to_string(int_cents) + " Cents";
		}
		else {
			int val = amount;
			if (val !=100) {
				printOut = one_19[Ldight] + " hundred and " + one_19[rdight] + "  dollars and " + to_string(int_cents) + " Cents";
			}
			else {
				
				printOut = one_19[Ldight] + " hundred  dollars and " + to_string(int_cents) + " Cents";
			}
			
		}
	}
	else if (amount < 10000)
	{
		int rdight = ((int)amount % 1000);
		int Ldight = (int)amount / 1000;
		int num_val, p1, p2;

		if (rdight >= 20 && rdight <= 999) {
			
			if (rdight >= 20 && rdight <= 99) {
				num_val = rdight;
				p1 = num_val % 10;
				p2 = num_val / 10;
				printOut = one_19[Ldight] + " thousand and " + twenty_90[p2] + " " + one_19[p1] + "  dollars and " + to_string(int_cents) + " Cents";
			}
			else {
				int p3,p4;
				num_val = rdight;			
				p2 = num_val / 100;
				p1 = num_val % 100;
				p3 = p1 / 10;
				p4 = p1 % 10;
				printOut = one_19[Ldight] + " thousand " + one_19[p2] + " hundred and " + twenty_90[p3] + " " + one_19[p4] + "  dollars and " + to_string(int_cents) + " Cents";

			}	
		}
		else {
			if (amount <= 1000) {
				printOut = one_19[Ldight] + " thousand dollars and " + to_string(int_cents) + " Cents";
			}
			else {
				printOut = one_19[Ldight] + " thousand " + one_19[rdight] +" dollars and " + to_string(int_cents) + " Cents";
			}
			
		}
		
	}
	return printOut;
}

/*



*/