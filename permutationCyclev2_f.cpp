#include <iostream>
#include "_array_functions_.h"

using namespace std;

int** permutationCyclev2_print(int** matrix, unsigned l)
{
	int* S = new int[l];
	int* P = new int[l];
	S = matrix[0];
	P = matrix[1];
	int* addedNumbers = new int[l];
	int NLPos = 0;
	int** resultMatrix = new int*[l];
	int RMI = 0;
	int RMJ = 0;

	for (size_t i = 0; i < l; i++)
	{
		resultMatrix[i] = new int [l];
	}

	int currentN;
	for (size_t i = 0; i < l; i++)
	{
		if (checkIfAdded(addedNumbers, S[i], l))
			continue;
		if (S[i] == P[i])
		{
			addedNumbers[NLPos] = S[i];
			NLPos++;
			continue;
		}
		currentN = S[i];
		addedNumbers[NLPos] = currentN;
		NLPos++;
		resultMatrix[RMI][RMJ] = currentN;
		RMJ++;
		while (currentN != P[i])
		{
			addedNumbers[NLPos] = P[i];
			NLPos++;
			resultMatrix[RMI][RMJ] = P[i];
			RMJ++;
			//FIND NEXT I
			for (size_t j = 0; j < l; j++)
			{
				if (S[j] == P[i])
				{
					i = j;
					break;
				}
			}

		}
		RMI++;
		RMJ = 0;
		i = 0;
	}

	for (size_t i = 0; i < l; i++)
	{
		if(resultMatrix[i][0] != -842150451)
		cout << "(";
		for (size_t j = 0; j < l; j++)
		{

			if (resultMatrix[i][j] != -842150451)
				if(resultMatrix[i][j+1] == -842150451)
					cout << resultMatrix[i][j];
				else
					cout << resultMatrix[i][j] << " ";
			else
				break;
		}
		if (resultMatrix[i][0] != -842150451)
		cout << ")";
	}

	return 0;

	for (size_t i = 0; i < l; i++)
	{
		delete[] resultMatrix[i];
	}
	delete[] resultMatrix;
}