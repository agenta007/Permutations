#include <iostream>
#include "_array_functions_.h"

struct Element
{
	bool written;
	char value;
};

bool areAllWrittenCP1(Element* arr, int l)
{
	for (size_t i = 0; i < l; i++)
	{
		if (arr[i].written == false)
		{
			return false;
		}
	}
	return true;
}

bool isItAddedCP1(Element* arr, int l, int n)
{
	for (size_t i = 0; i < l; i++)
	{
		if (arr[i].value == n)
		{
			if (arr[i].written == true)
				return true;
			else
				return false;
		}
	}
}

//TAKES TWO PERMUTATIONS AND COMPOSES THEM
std::string compositionReworkv2(std::string cyclerPermutation)
{
	//p2 * p1
	//find length
	std::string wholeLine = "";
	wholeLine += cyclerPermutation;
	unsigned lineL = wholeLine.length();
	bool midOfString = false;
	std::string p1, p2;
	p1 = "";
	p2 = "";
	for (size_t i = 0; i < lineL; i++)
	{
		if (midOfString)
		{
			if (wholeLine[i] == (char)0)
			{
				break;
			}
			p2 += wholeLine[i];
			continue;
		}
		if (wholeLine[i] == '&')
		{
			midOfString = true;
			continue;
		}
		p1 += wholeLine[i];
	}
	std::string p1tmp, p2tmp;
	p1tmp = "";
	p2tmp = "";
	int max = 0;
	int max2 = 0;
	int p1l = p1.length();
	int p2l = p2.length();


	for (size_t i = 1; i < p1l; i++)
	{
		if (p1[i] != ' ')
		{
			p1tmp += p1[i];
		}
	}
	for (size_t i = 1; i < p2l; i++)
	{
		if (p2[i] != ' ')
		{
			p2tmp += p2[i];
		}
	}
	if (p1tmp[0] == '(')
		p1 = p1tmp;
	else
		p1 = "(" + p1tmp;
	if (p2tmp[0] == '(')
		p2 = p2tmp;
	else
		p2 = "(" + p2tmp;
	p1l = p1.length();
	p2l = p2.length();



	for (size_t i = 1; i < p1l - 1; i++)
	{
		if (p1[i] == '(' || p1[i] == ')')
			continue;
		if ((p1[i] - 48) > max)
		{
			max = p1[i] - 48;
		}
	}

	int a;
	for (size_t i = 1; i < p2l - 1; i++)
	{
		if (p2[i] == '(' || p2[i] == ')')
			continue;
		a = p2[i] - 48;
		if (a > max2)
		{
			max2 = a;
		}
	}

	if (max2 > max)
		max = max2;

	std::string composition = "(";

	//find composition

	char mapping;
	char numToWrite = -1;
	bool isNumChanged = false;
	bool isMappingSelected = false;
	bool endOfCycle = false;
	char firstEl = p1[1];
	bool isThisAdded = false;
	bool sochiKymSebeSi = false;
	Element* list = new Element[max];
	for (size_t i = 0; i < max; i++)
	{
		list[i].value = i + 1;
		list[i].written = false;
	}

	while (!areAllWrittenCP1(list, max))
	{
		for (size_t i = 1; i <= max;)
		{
			if (endOfCycle == true && !isThisAdded)
			{
				int compositionL = composition.length();
				if (composition[compositionL - 1] != ')')
					composition += ")(";
			}
			if (!endOfCycle)
			{
				composition += '0' + i;
				for (size_t iList = 0; iList < max; iList++)
				{
					if (list[iList].value == '0' + i - 48)
					{
						list[iList].written = true;
						break;
					}
				}
			}
			isThisAdded = isItAddedCP1(list, max, i);
			if (isThisAdded && endOfCycle)
			{
				i++;
				continue;
			}
			isThisAdded = false;
			endOfCycle = false;
			for (size_t j = 1; j < p2l - 1; j++)
			{
				if (p2[j] == '0' + i)
					if (p2[j + 1] == ')')
					{
						for (int k = j; k > -1; k--)
						{
							if (p2[k - 1] == '(')
							{
								mapping = p2[k];
								isMappingSelected = true;
								break;
							}
						}
					}
					else
					{
						mapping = p2[j + 1];
						isMappingSelected = true;
						break;
					}
			}

			if (!isMappingSelected)
			{
				mapping = '0' + i;
			}

			for (size_t j = 1; j < p1l - 1; j++)
			{
				if (p1[j] == mapping)
				{
					if (p1[j + 1] - 48 == i)
					{
						sochiKymSebeSi = true;
						break;
					}
					if (p1[j + 1] == ')')
					{
						for (int k = j; k > -1; k--)
						{
							if (p1[k - 1] == '(')
							{
								if (p1[k] == firstEl)
								{
									endOfCycle = true;
								}
								if (p1[k] - 48 == i)
								{
									sochiKymSebeSi = true;
									break;
								}

								numToWrite = p1[k];
								isNumChanged = true;
								break;
							}
						}
					}
					else
					{
						numToWrite = p1[j + 1];
						isNumChanged = true;
						break;
					}
					if (isNumChanged)
						break;
				}
			}
			if (sochiKymSebeSi)
			{
				int compositionL = composition.length();
				if (composition[compositionL - 1] != '(')
					composition += '(';
				composition += '0' + i;
				composition += ')';
				endOfCycle = true;
				for (size_t iList = 0; iList < max; iList++)
				{
					if (list[iList].value == '0' + i - 48)
					{
						list[iList].written = true;
						break;
					}
				}
				continue;
			}
			if (numToWrite != -1)
				i = numToWrite - 48;
			else
				i = i - 48;
			if (!isNumChanged)
			{
				numToWrite = mapping;
				i = numToWrite - 48;
			}
			//flags reset
			isNumChanged = false;
			isMappingSelected = false;
		}
	}

	//composition is whole permutation with (1462)|(3)(5)|, part between | | must be now deleted

	//std::string newComp = "";
	//
	//int compL = composition.length();
	//for (size_t i = 0; i < compL; i++)
	//{
	//	if (composition[i + 1] == '(' && composition[i + 3] == ')')
	//	{
	//		i += 2;
	//		continue;
	//	}
	//	newComp += composition[i];
	//}
	//
	//std::cout << "Composition of " << p2 << " x " << p1 << " (without single cycles - (1)(2)(3)..): " << newComp << "\n";

	return composition;
}


int iterationA(std::string input)
{
	std::string firstPer = input;
	unsigned iL = input.length();
	int arr[100];
	int arrPos = 0;
	for (size_t i = 0; i < iL; i++)
	{
		if (input[i] != '(' && input[i] != ')' && input[i] != ' ')
		{
			arr[arrPos] = input[i] - 48;
			arrPos++;
		}
	}

	unsigned permutationLength = arrPos;
	int* permutation = new int[permutationLength];
	for (size_t i = 0; i < permutationLength; i++)
	{
		permutation[i] = arr[i];
	}

	std::string Input, output;
	unsigned outputL;
	int* function;
	int** matrix = new int* [2];
	unsigned functionL;
	std::string outputStr = firstPer;
	unsigned outputStrL = outputStr.length();
	unsigned outputPos = 0;
	for (size_t i = 0; i < 15; i++)
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
		
		matrix[0] = permutation;
		matrix[1] = function;
		log_array(matrix, 2, permutationLength);
		bool isThisK = identitetCheck(matrix, 2, permutationLength);
		if (isThisK)
			return i;
		
	}
}