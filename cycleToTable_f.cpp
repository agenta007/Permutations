#include <iostream>
#include "_array_functions_.h"

struct Column
{
	int s;
	int p;
};

int** cycleToTable(std::string inputStr)
{
	std::string input;
	input = inputStr;

	Column* columns = new Column[input.length()];
	int firstOfCycle = -1;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '(' || input[i] == ')' || input[i] == ' ')
			continue;
		if (input[i+1] == ')')
		{
			columns[i].s = input[i] - 48;
			columns[i].p = firstOfCycle;
			firstOfCycle = -1;
			continue;
		}
		if (firstOfCycle == -1)
		{
			firstOfCycle = input[i] - 48;
		}
		columns[i].s = input[i]- 48;
		columns[i].p = input[i+1] - 48;
	}

	for (size_t i = 0; i < input.length(); i++)
	{
		if (columns[i].s < 0)
			continue;
		std::cout << columns[i].s << " ";
	}
	std::cout << "\n";
	for (size_t i = 0; i < input.length(); i++)
	{
		if (columns[i].p < 0)
			continue;
		std::cout << columns[i].p << " ";
	}
	std::cout << "\n";

	Column* newColumns = new Column[input.length()];
	int NCP = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		for (size_t j = 0; j < input.length(); j++)
		{
			if (columns[j].s+1 == i)
			{
				newColumns[NCP].s = columns[j].s;
				newColumns[NCP].p = columns[j].p;
				NCP++;
				break;
			}
		}
	}
	int** returnMatrix = new int* [2];
	for (size_t i = 0; i < 2; i++)
	{
		returnMatrix[i] = new int[input.length()];
	}

	for (size_t i = 0; i < input.length(); i++)
	{
		returnMatrix[0][i] = newColumns[i].s;
		returnMatrix[1][i] = newColumns[i].p;
	}
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < input.length(); j++)
		{
			if (j + 1 != input.length())
				if(returnMatrix[i][j] > 0)
				std::cout << returnMatrix[i][j] << " ";
			else
				if (returnMatrix[i][j] > 0)
				std::cout << returnMatrix[i][j];
		}
		std::cout << std::endl;
	}
	return returnMatrix;
	for (size_t i = 0; i < 2; i++)
	{
		delete[] returnMatrix[i];
	}
	delete[] returnMatrix;
}