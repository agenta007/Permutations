#include <iostream>
#include "_array_functions_.h"

using namespace std;

struct number
{
	int n;
	bool isItZadraskano;
};

struct cycleElements
{
	char str[1001];
	int length;
};

bool areAllZadraskani(number* arr, int l)
{
	for (size_t i = 0; i < l; i++)
	{
		if (arr[i].isItZadraskano == false)
		{
			return false;
		}
	}
	return true;
}

bool isItZadraskano(number* arr, int l, int n)
{
	for (size_t i = 0; i < l; i++)
	{
		if (arr[i].n == n)
		{
			if (arr[i].isItZadraskano == true)
			{
				return true;
			}
		}
	}
	return false;
}

string permutationCycle(int** matrix, unsigned m)
{
	//LIST WITH NUMBERS
	number* numberList = new number[m];
	//PERMUTATION
	int* permutation = new int[m];
	permutation = matrix[1];
	cycleElements* toBeStringed = new cycleElements[m];
	int toBeStringedPos = 0;
	int currentStrPos = 0;
	int cycles = 0;

	for (size_t i = 0; i < m; i++)
	{
		numberList[i].n = matrix[0][i];
		numberList[i].isItZadraskano = false;
	}

	int currentN;
	int j;
	for (size_t i = 0; i < m; i++)
	{
		if (!areAllZadraskani)
			break;
		currentN = numberList[i].n;
		currentN = numberList[i].isItZadraskano = true;
		toBeStringed[toBeStringedPos].str[currentStrPos] = '0' + currentN;
		currentStrPos++;
		j = i;

		int chisloZaZadraskvane;
		while (currentN != permutation[j])
		{
			chisloZaZadraskvane = permutation[j];
			if (isItZadraskano(numberList, m, chisloZaZadraskvane))
			{
				break;
			}

			for (size_t k = 0; k < m; k++)
			{
				if (numberList[k].n == chisloZaZadraskvane)
				{
					numberList[k].isItZadraskano = true;
					toBeStringed[toBeStringedPos].str[currentStrPos] = '0' + chisloZaZadraskvane;
					currentStrPos++;
					break;
				}
			}
			
			for (size_t k = 0; k < m; k++)
			{
				if (numberList[k].n == chisloZaZadraskvane)
				{
					j = k;
					break;
				}
			}
		}
		toBeStringed[toBeStringedPos].str[currentStrPos] = 'n';
		toBeStringed[toBeStringedPos].length = currentStrPos + 1;
		currentStrPos = 0;
		toBeStringedPos++;
		cycles++;

	}

	int finalStringLength = (m * 2) - cycles + 2 * cycles + 2;
	char* finalString = new char[finalStringLength];
	int finalStringPos = 0;
	finalString[0] = '(';
	finalStringPos++;
	finalString[finalStringLength - 1] = ')';
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < toBeStringed[i].length; j++)
		{
			finalString[finalStringPos] = toBeStringed[i].str[j];
			finalStringPos++;
		}
	}

	string str = "";
	for (size_t i = 0; i < finalStringLength; i++)
	{
		str += finalString[i];
	}

	return str;

	delete[] permutation;
	delete[] numberList;
}