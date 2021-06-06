#include <iostream>
#include "_array_functions_.h"

using namespace std;

int fill_array(int** arrName, unsigned n, unsigned m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> arrName[i][j];
		}
	}
	return 0;
}