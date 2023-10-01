// Chapter 9 - Programming Challenge 8, Search Benchmarks
// This program compares the number of comparisons used by linear
// search vs. binary search to find a value.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int linearSearchBench(int[], int, int);
int binarySearchBench(int[], int, int);
void print_array(int*, int);
void sort_array(int* arr_param, int size);

int main()
{
	const int SIZE = 251;
	int numCompares;         // Accumulator to count the number of comparisons 

	int arr_tests[SIZE] = {};

	for (int i = 0; i < SIZE; i++)
	{
		int rand_num = rand() % 1001 + 2000;
		for (int p = 0; p < i;)
		{
			if (rand_num == arr_tests[p])
			{
				rand_num = rand() % 1001 + 2000;
				p = 0;
			}
			else
				p++;
		}
		arr_tests[i] = rand_num;
	}


	sort_array(arr_tests, SIZE);
	arr_tests[SIZE - 1] = 5000;
	print_array(arr_tests, SIZE);

	int arr_test_valid_values[] = { arr_tests[0], arr_tests[SIZE / 2] , arr_tests[SIZE - 1] };
	int arr_test_invalid_values[] = { 100, 2300, 9000 };

	cout << "*************** searching for VALID values *************\n";
	for (auto one_val : arr_test_valid_values)
	{
		numCompares = linearSearchBench(arr_tests, SIZE, one_val);
		cout << "Linear Search. Searching for " << one_val << ", " << numCompares
			<< " comparisons made.\n";

		numCompares = binarySearchBench(arr_tests, SIZE, one_val);
		cout << "Binary Search. Searching for " << one_val << ", " << numCompares
			<< " comparisons made.\n";
	}

	cout << "\n*************** searching for INVALID values *************\n";
	for (auto one_val : arr_test_invalid_values)
	{
		numCompares = linearSearchBench(arr_tests, SIZE, one_val);
		cout << "Linear Search. Searching for " << one_val << ", " << numCompares
			<< " comparisons made.\n";

		numCompares = binarySearchBench(arr_tests, SIZE, one_val);
		cout << "Binary Search. Searching for " << one_val << ", " << numCompares
			<< " comparisons made.\n";
	}
	return 0;
}
void print_array(int* arr_param, int size)
{
	
	for (int i = 0; i < size;++i) {
		cout << setw(8) << *(arr_param + i) ;
		if ((i + 1) % 18 == 0)
			cout << endl;
   }
	cout << endl;

}
void sort_array(int* arr_param, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(arr_param + i) > * (arr_param + j))
			{
				int temp = *(arr_param + i);
				*(arr_param + i)=*(arr_param + j);
				*(arr_param + j) = temp;
			}

		}
	}

}
/********************************************************************
 *                       linearSearchBench                          *
 * Called by: main                                                  *
 * Passed   : An array to search in, the number of elements in      *
 *            the array, and the value to search for                *
 * Purpose  : To count the number of comparisons made to complete   *
 *            the linear search                                     *
 * Returns  : The comparison count                                  *
 * Note     : Linear search can be written to be more efficient than*
 *            the algorithm used below in determining that a value  *
 *            is NOT present in the array if the array elements     *
 *            are known to be in sorted order.                      *
 ********************************************************************/
int linearSearchBench(int arr_param[], int size, int inp_val)
{
	int  comparisons = 0;
	bool found = false;
	for (int i = 0; i < size; i++) 
	{
		comparisons = comparisons + 1;
		if (arr_param[i]== inp_val)			
			found = true;		
		if (found)
			return comparisons;
	}	
}

/******************************************************************
 *                       binarySearchBench                        *
 * Called by: main                                                *
 * Passed   : An array to search in, the number of elements in    *
 *            the array, and the value to search for              *
 * Purpose  : To count the number of comparisons made to complete *
 *            the binary search                                   *
 * Returns  : The comparison count                                *
 ******************************************************************/
int binarySearchBench(int arr_param[], int size, int inp_val)
{
	bool found = false;
	int  first = 0,
		last = size - 1,
		middle,
		comparisons = 0;
	while (first <= last && !found) {
		comparisons = comparisons + 1;
		middle = (first + last) / 2;
		if (inp_val> arr_param[middle]){
			first = middle + 1;
		}else if(inp_val < arr_param[middle]) {
			last = middle - 1;
		}
		else {
			found = true;
		}
		if (found)
			return comparisons;
	}
   return comparisons;
}
