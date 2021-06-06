#include <iostream>
#include "_array_functions_.h"
std::string reversePermutation(std::string input)
{
	unsigned inputL = input.length();
	unsigned cyclesCnt = 0;
	for (size_t i = 0; i < inputL; i++)
	{
		if (input[i] == ')')
			cyclesCnt++;
	}
	unsigned maxLength = 0;
	unsigned oldMaxLength = 0;
	for (size_t i = 0; i < inputL; i++)
	{
		if (input[i]==')')
		{
			maxLength++;
			if (maxLength > oldMaxLength)
			{
				oldMaxLength = maxLength;
				maxLength = 0;
			}
			continue;
		}
		maxLength++;
	}
	std::string* strArr = new std::string[cyclesCnt];
	unsigned strArrPos = 0;
	for (size_t i = 0; i < inputL; i++)
	{
		if (input[i] == ')' and input[i+1] == (char) 0)
		{
			strArr[strArrPos] += input[i];
			break;
		}
		strArr[strArrPos] += input[i];
		if (input[i] == ')')
		{
			strArrPos++;
		}
	}

	char* tempString = new char[maxLength];
	for (size_t i = 0; i < cyclesCnt; i++)
	{
		if (strArr[i][0] == (char)0)
			break;
		for (int j = strArr[i].length(); j > -1; j--)
		{
			if (strArr[i][j] == '(')
				strArr[i][j] = ')';
			if (strArr[i][j] == ')')
				strArr[i][j] = '(';

			tempString += strArr[i][j];
		}
		strArr[i] = tempString;
		for (size_t j = 0; j < maxLength; j++)
		{
			tempString[j] = (char)0;
		}
	}
	std::string finalString = "";
	for (size_t i = 0; i < 100; i++)
	{
		if (strArr[i][0] == (char)0)
			break;
		finalString += strArr[i];
	}
	delete[] strArr;
	return finalString;
}