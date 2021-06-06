#include <iostream>
#include "_array_functions_.h"

using namespace std;

bool checkSurectivePermutation(int** arr, unsigned n, unsigned m)
{
	int cnt = 0;
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (i == j)
				continue;
			if (arr[1][i] == arr[0][j])
				cnt++;
		}
		if (cnt == 0)
		{
			return false;
		}
	}
	return true;
}