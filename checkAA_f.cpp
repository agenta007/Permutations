#include <iostream>
#include "_array_functions_.h"

using namespace std;

bool checkAA(int** arr, unsigned n, unsigned m)
{
	for (unsigned i = 0; i < m; i++)
	{
		if (arr[0][i] == arr[1][i])
		{
			return true;
		}
	}
	return false;
}