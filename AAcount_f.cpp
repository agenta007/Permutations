#include <iostream>
#include "_array_functions_.h"

using namespace std;

int AAcount(int** arr, unsigned n, unsigned m)
{
	int cnt = 0;
	for (size_t i = 0; i < m; i++)
	{
		if (arr[0][i] == arr[1][i])
		{
			cnt++;
		}
	}
	return cnt;
}