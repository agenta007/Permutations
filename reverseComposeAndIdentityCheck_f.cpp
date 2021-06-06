#include <iostream>
#include "_array_functions_.h"
void reverseComposeAndIdentityCheck(std::string reversed, unsigned n, unsigned m)
{
	std::cout << "Re-enter this string: "<< "\n";
	std::cout << reversed << "\n";
	std::string original = reversePermutationv2();
	std::cout << original << "\n";
	std::cout << "Re-enter both strings separeted by &" << "\n";
	compositionToTable();
	std::cout << "Re-enter S without spaces:" << "\n";
	std::string S;
	std::cin >> S;
	std::cout << "Re-enter P without spaces:" << "\n";
	std::string P;
	std::cin >> P;

	//S AND P STRINGS CONVERT

	char* Sp = new char[S.length()];
	char* Pp = new char[P.length()];
	unsigned SpPos = 0;

	for (size_t i = 0; i < S.length(); i++)
	{
		if (S[i + 1] == (char)0 and S[i] == (char)0)
			break;
		if (S[i] != (char)0)
		{
			Sp[SpPos] = S[i];
			SpPos++;
		}
	}

	for (size_t i = 0; i < P.length(); i++)
	{
		Pp[i] = P[i];
	}

	int** matrix = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	for (size_t i = 0; i < S.length(); i++)
	{
		matrix[0][i] = Sp[i] - 48;
	}

	for (size_t i = 0; i < P.length(); i++)
	{
		matrix[1][i] = Pp[i] - 48;
	}

	log_array(matrix, n, m);
	bool idCh = identitetCheck(matrix, n, m);
	idCh ? std::cout << "Identical." << "\n" : std::cout << "Not identical." << "\n";

	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}