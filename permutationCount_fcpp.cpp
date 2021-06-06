#include <iostream>
#include "_array_functions_.h"

int permutationCount(unsigned length)
{
	int factorielMultiplier = length;
	int count = 1;
	while (factorielMultiplier != 1)
	{
		count *= factorielMultiplier;
		factorielMultiplier--;
	}
	return count;
}