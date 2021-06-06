#include <iostream>
#include <string>
#include "_array_functions_.h"

struct Element
{
	bool written;
	char value;
};

bool areAllWrittenCP(Element* arr, int l)
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

bool isItAddedCP(Element* arr, int l, int n)
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
std::string compositionRework(std::string cyclerPermutation)
{
	//p2 * p1
	//find length
	std::string wholeLine = "(";
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

	while (!areAllWrittenCP(list, max))
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
			isThisAdded = isItAddedCP(list, max, i);
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

	std::string newComp = "";

	int compL = composition.length();
	for (size_t i = 0; i < compL; i++)
	{
		if (composition[i + 1] == '(' && composition[i + 3] == ')')
		{
			i += 2;
			continue;
		}
		newComp += composition[i];
	}

	std::cout << "Composition of " << p2 << " x " << p1 << " (without single cycles - (1)(2)(3)..): " << newComp << "\n";

	return newComp;
}


int commutationCheck()
{
	std::cout << "Commutation check. Is p1xp2 == p2p1? " << "\n";
	std::cout << "Enter two permutations: " << "\n";
	std::string input;
	std::cin.ignore();
	std::getline(std::cin, input);
	std::string p1p2 =  compositionRework(input);
	std::cout << "Now enter same permutations, but in reverse order" << "\n";
	std::getline(std::cin, input);
	std::string p2p1 = compositionRework(input);
	std::cout <<p1p2 << std::endl;
	std::cout <<p2p1 << std::endl;
	std::cout << "Of course p1p2 == p2p1 only when p1 and p2 are identical." << "\n";
	return 0;
}