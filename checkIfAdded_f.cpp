#include <iostream>
#include "_array_functions_.h"

using namespace std;

bool checkIfAdded(int* arr, int n, int l)
{
	for (size_t i = 0; i < l; i++)
	{
		if (n == arr[i])
		{
			return true;
		}
	}
	return false;
}