#include <iostream>
#include "_array_functions_.h"
std::string reversePermutationv2()
{
	char input[100];
	std::cout << "Enter permutation and get reversed: " << "\n";
	std::cin.ignore();
	std::cin.getline(input, sizeof(input));
	unsigned il = 0;
	for (size_t i = 0; i < 100; i++)
	{
		if (input[i] == (char)0)
			il = i;
	}
	unsigned stPos, endPos;
	unsigned subStrL;
	char subStr[1001];
	for (size_t i = 0; i < il; i++)
	{
		if (input[i] == '(')
			stPos = i;
		for (size_t j = i; j < il; j++)
		{
			if (input[j] == ')')
			{
				endPos = j;
				break;
			}
		}
		subStrL = endPos - stPos + 1;
		int k = stPos;
		for (int j = subStrL-1; j > -1; j--)
		{
			subStr[j] = input[k];
			k++;
		}
		subStr[subStrL - 1] = ')';
		subStr[0] = '(';
		k = 0;
		for (size_t i = stPos; i <= endPos; i++)
		{
			input[i] = subStr[k];
			k++;
		}
		i = endPos;
	}
	return input;
}