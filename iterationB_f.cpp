#include <iostream>
#include "_array_functions_.h"

int* getLengthsOfPer(std::string input)
{
	int arr[100];
	int arrPos = 0;
	int inputL = input.length();
	int cnt;
	for (size_t i = 0; i < inputL; i++)
	{
		cnt = 0;
		for (size_t j = i; j < inputL; j++)
		{
			if (input[j] == '(' || input[j] == ' ')
				continue;
			if (input[j] == ')')
			{
				i = j + 1;
				break;
			}
			cnt++;
		}	
		arr[arrPos] = cnt;
		arrPos++;

	}
	int* lengths = new int[arrPos];
	for (size_t i = 0; i < arrPos; i++)
	{
		lengths[i] = arr[i];
	}
	return lengths;
}

int iterationB(std::string input)
{
	std::string firstPer = input;
	//MUST BE SEPARATED WITH &
	int* lengthsOfPer = getLengthsOfPer(input);
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << lengthsOfPer[i] << " ";
	}
	std::cout << std::endl;

	int NOK;
	for (size_t i = 2; i < 1000; i++)
	{
		if (i % lengthsOfPer[0] == 0 && i % lengthsOfPer[1] == 0)
		{
			NOK = i;
			break;
		}
	}


	int arr[100];
	int arrPos = 0;
	unsigned permutationLength = arrPos;

	std::string Input, output;
	unsigned outputL;
	int* function;
	int** matrix = new int* [2];
	unsigned functionL;
	std::string outputStr = firstPer;
	unsigned outputStrL = outputStr.length();
	unsigned outputPos = 0;
	for (size_t i = 0; i < NOK; i++)
	{
		Input = "";
		for (size_t j = 0; j < outputStrL; j++)
		{
			Input += outputStr[j];
			//if(outputStr[j] != '(' && outputStr[j+1] != ')')
			//	Input += " ";
		}
		Input = firstPer + " & " + Input;
		outputStr = compositionReworkv2(Input);
		//(1(1) BUG HANDLE
		if (outputStr[1] != '(' && outputStr[1] != ')')
		{
			if (outputStr[2] == '(')
			{
				std::string tempComp = "";
				for (size_t j = 2; j < outputStr.length(); j++)
				{
					tempComp += outputStr[j];
				}
				outputStr = tempComp;
			}
		}
		arrPos = 0;
		for (size_t j = 0; j < outputStr.length(); j++)
		{
			if (outputStr[j] != '(' && outputStr[j] != ')' && outputStr[j] != (char)0)
			{
				arr[arrPos] = outputStr[j] - 48;
				arrPos++;
			}
		}
		functionL = arrPos;
		function = new int[functionL];
		for (size_t j = 0; j < functionL; j++)
		{
			function[j] = arr[j];
		}
		arrPos = 0;
	}
		bool isThisK = identitetCheck(matrix, 2, permutationLength);
		if (isThisK)
			std::cout << "True. f^" << NOK << " == id" << "\n";

	return NOK;
}