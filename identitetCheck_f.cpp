#include <iostream>
#include "_array_functions_.h"

using namespace std;

bool identitetCheck(int** arr, unsigned n, unsigned m)
{
	int cnt = AAcount(arr, n, m);
	if (m == cnt)
		return true;
	else
		return false;
}