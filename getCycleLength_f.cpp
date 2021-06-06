#include <iostream>
#include "_array_functions_.h"

int getCycleLength(int* cycle)
{
	int length = 0;
	for (size_t i = 0; i < 100; i++)
	{
		if (cycle[i] < 0 && cycle[i] > 1000000)
			length++;
	}
	return length;
}