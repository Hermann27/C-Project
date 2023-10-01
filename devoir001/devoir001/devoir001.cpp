// devoir001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
#include "SnowData.h"

void print_array_elements(SnowData[], int);
void sort_by_base_depth(SnowData[], int);
void sort_by_date(SnowData[], int);
double get_average_base_depth(SnowData[], int);
int main()
{
	SnowData jan_snow[7] = { SnowData("Jan 15",34.5),SnowData("Jan 16",23.6),
								 SnowData("Jan 17",25.5), SnowData("Jan 18",31.5) ,
								  SnowData("Jan 19",40.6) ,SnowData("Jan 20",30.9) ,
					SnowData("Jan 21",38.4) };
	cout << setprecision(2) << fixed << showpoint;

	cout << " --- array at start of the program --\n";
	print_array_elements(jan_snow, 7);
	cout << "Average base depth for the period "
		<< jan_snow[0].getSnow_date() << " - "
		<< jan_snow[6].getSnow_date() << " : "
		<< get_average_base_depth(jan_snow, 7) << endl;

	sort_by_base_depth(jan_snow, 7);
	cout << " --- array after sort by base_depth --\n";
	print_array_elements(jan_snow, 7);

	sort_by_date(jan_snow, 7);
	cout << " --- array after sort by date --\n";
	print_array_elements(jan_snow, 7);

	return 0;
}
double get_average_base_depth(SnowData _array[], int size)
{
	double total_depth = 0;
	for (int i = 0; i < size; i++)
	{

		total_depth= total_depth+ _array[i].getBase_depth();

	}
	return total_depth / 7;
}
void print_array_elements(SnowData _array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;_array[i].print();
	}
	
}

void sort_by_base_depth(SnowData _array[], int size)
{
		
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (_array[i].getBase_depth()> _array[j].getBase_depth())
			{
				SnowData tempL= _array[i];
				_array[i].setBase_depth(_array[j].getBase_depth());
				_array[i].setSnowDate(_array[j].getSnow_date());
				_array[j].setBase_depth(tempL.getBase_depth());
				_array[j].setSnowDate(tempL.getSnow_date());
			}
			
		}
	}
}
void sort_by_date(SnowData _array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (_array[i].getSnow_date() > _array[j].getSnow_date())
			{
				SnowData NewSnowDataObject = _array[i];
				_array[i].setBase_depth(_array[j].getBase_depth());
				_array[i].setSnowDate(_array[j].getSnow_date());
				_array[j].setBase_depth(NewSnowDataObject.getBase_depth());
				_array[j].setSnowDate(NewSnowDataObject.getSnow_date());
			}

		}
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
