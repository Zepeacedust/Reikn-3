#include <iostream>
#include <chrono>

constexpr auto LENGTH = 100000;


/*
	tími bubblesort = U.Þ.B Hálftími 
	tími qsort = 490 ms
	ég held að qsort sé að nota quicksort og er þá o(n * log(n))
	bubblesort er o(n^2)
*/


using namespace std;
using namespace chrono;
///<summary>
///in place swap af tvemur integerum
///</summary>
void swap(int* a, int* b)
{
	int c = *a;
	a = b;
	*b = c;
}
///<summary>
///sorta lista in place með bubblesort
///</summary>
void inplaceBubblesort(int* arr, int length)
{
	int i, j;
	for (i = 0; i < length - 1; i++) 
	{
		// Last i elements are already in place  
		for (j = 0; j < length - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
}

///<summary>
///fyrir qsort
///</summary>
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int *numeros = new int[LENGTH];
	steady_clock::time_point begin;
	steady_clock::time_point end;
	
	for (long int j = 0; j < LENGTH; j++)
	{
		numeros[j] = LENGTH - j;
	}
	begin = steady_clock::now();
	qsort(numeros, LENGTH, sizeof(int), compare);
	end = steady_clock::now();
	cout << "Time qSort = " << duration_cast<milliseconds>(end - begin).count() << "[ms]" << endl;


	for (long int j = 0; j < LENGTH; j++)
	{
		numeros[j] = LENGTH - j;
	}
	begin = steady_clock::now();
	inplaceBubblesort(numeros, LENGTH);
	end = steady_clock::now();
	cout << "Time bubble sort = " << duration_cast<milliseconds>(end - begin).count() << "[ms]" << endl;

}
