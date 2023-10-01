// Assignment_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
void printArray(int *dArrays,int );
double getAverage(int* dArrays, int );
void sortArray(int* dArrays, int );
int getMaximum(int* dArrays, int );
int main()
{
	bool IsNegative=false;
    

	int NumberOfStudents, NumberOfMovies;
	int* dArrayStudents;
	NumberOfStudents = 0;
	NumberOfMovies = 0;
	cout << "How many students were surveyed? ";
	cin >> NumberOfStudents;
	do {

		if (NumberOfStudents<0 ) {
			cout << "Number cannot be negative: Please enter a nonnegative value:";
			cin >> NumberOfStudents;
		}
		
	} while (NumberOfStudents<0 );
	
	cout << "Enter the number of movies each student saw. " << endl;
	//allocation of students arrays in memory
	dArrayStudents = new int[NumberOfStudents];
	for (int i = 0;i < NumberOfStudents;i++) {
		cout << "Student " << (i + 1)<<" : " ;
		cin >> NumberOfMovies;
		do {
			if (NumberOfMovies < 0) {
				cout << "Number cannot be negative: Please enter a nonnegative value:";
				cin >> NumberOfMovies;
			}

		} while (NumberOfMovies < 0);
		dArrayStudents[i] = NumberOfMovies;

	}

	cout << "-------------Bebore sort-------------" << endl;
	printArray(dArrayStudents, NumberOfStudents);
	cout << "-------------after sort-------------" << endl;
	sortArray(dArrayStudents, NumberOfStudents);
	printArray(dArrayStudents, NumberOfStudents);
	cout << "The average number of movies seen is  "<< getAverage(dArrayStudents, NumberOfStudents) << endl;
	cout << "The maximun value is " << getMaximum(dArrayStudents, NumberOfStudents) << endl;
	
	
	// dynamic pointer delocation
	delete []dArrayStudents;
	dArrayStudents = NULL;
	return 0;
}
void printArray(int* dArrays, int size) {
	for (int i = 0; i < size;++i) {
		cout << setw(8) << dArrays[i];
		if ((i + 1) % size == 0)
			cout << endl;
	}
	cout << endl;

}


double getAverage(int* dArrays, int size) {

	double Average = 0;
	for (int i = 0; i < size; i++){
		Average = Average + dArrays[i];
	}
	return Average / size;
}
void sortArray(int* dArrays, int size) {

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (dArrays[i] > dArrays[j])
			{
				int temp = dArrays[i];
				dArrays[i] = dArrays[j];
				dArrays[j] = temp;
			}

		}
	}
}
int getMaximum(int* dArrays, int size) {
	return dArrays[size-1];
}
