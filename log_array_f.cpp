#include "_array_functions_.h"
#include <iostream>

using namespace std;

int log_array(int** arrName, unsigned n, unsigned m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (arrName[i][j] < 0)
				continue;
			if(j + 1 != m)
				cout << arrName[i][j] << " ";
			else
				cout << arrName[i][j];
		}
		cout << "\n";
	}
	return 0;
}