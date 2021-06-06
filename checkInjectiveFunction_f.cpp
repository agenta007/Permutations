#include <iostream>
#include "_array_functions_.h"

using namespace std;
bool checkInjectivePermutation(int** arrName, unsigned n, unsigned m)
{
	int cnt = 0;
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (j == i)
				continue;
			if (arrName[1][i] == arrName[1][j] && arrName[0][i] != arrName[0][j])
			{
				return false;
			}
		}
	}
	return true;
}