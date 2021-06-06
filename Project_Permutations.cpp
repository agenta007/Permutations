#include <iostream>
#include "_array_functions_.h"
#include <string>
using namespace std;

int main()
{
	//INPUT, MENU AND MATRIX SETUP
	cout << "Enter permutation length and 2 permutations:" << endl;
	int rows, cols;
	rows = 2;
	cin >> cols;
	cout << "Improvised Progam Menu" << endl;
	cout << "0-Terminate." << endl;
	cout << "1-zadacha - Ne e funkciq, postroqvane na matrica, vyvedete edno za otpechatvane." << endl;
	cout << "2 - Fill array" << endl;
	cout << "3 - Check if function is injective" << endl;
	cout << "4 - Check if function is surrective" << endl;
	cout << "5 - Check if function is a permutation" << endl;
	cout << "6 - Permutation count finder" << endl;
	cout << "7 - Proverka za nepodvijna tochka" << endl;
	cout << "8 - Namirane na broi nepodvijni tochki" << endl;
	cout << "9 - Proverka dali permutaciq e identitet" << endl;
	cout << "10 - Permutaciq kym nezavisimi cikli" << endl;
	cout << "11 - Namirane na duljinite na nezavisimite cikli" << endl;
	cout << "12 - Permutaciq ot nezavisimi cikli v tablichen vid" << endl;
	cout << "13 - Namirane na kompoziciqta na dve permutacii" << endl;
	cout << "14 - Namirane na obratnata na permutaciq" << endl;
	cout << "15 - Namira kompoziciqta na permutaciq chrez obratnata i i kazva dali e ravna na id" << endl;
	cout << "16 - Da se proveri dali dve razlichni ot identitet permutacii mogat da se kompozirat komutativno" << endl;
	cout << "17 - Namirane na minimalnoto k za koeto f^k==id" << endl;
	cout << "18 - Namirane na minimalnoto k za koeto f^k==id CHREZ namirane na NOK" << "\n";
	int inputN;
	//1 - not a function - create matrix
	int** matrix = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	while (1)
	{
		cout << "Select with input number: " << endl;
		cin >> inputN;
		if (inputN == 0)
		{
			cout << "You have seleceted 0 and terminated the program." << endl;
			return 0;
		}
		switch (inputN)
		{
		case 1: log_array(matrix, rows, cols); break;
		case 2: fill_array(matrix, rows, cols); break;
		case 3: cout << checkInjectivePermutation(matrix, rows, cols) << endl;; break;
		case 4: cout << checkSurectivePermutation(matrix, rows, cols) << endl;; break;
		case 5: 
		{
			if (checkInjectivePermutation(matrix, rows, cols) && checkSurectivePermutation(matrix, rows, cols))
			cout << "Permutaciq - syurektivna i biektivna" << endl;
		else
			cout << "Ne e permutaciq." << endl;
		}break;
		case 6:
		{
			cout << "Vyvedete broq na elementi i poluchete broq na permutacii" << endl;
			int N;
			cin >> N;
			cout << permutationCount(N) << endl;
		}break;
		case 7:checkAA(matrix, rows, cols) ? cout << "True" << endl : cout << "False" << endl;;break;
		case 8:cout << "Broqt na nepodvijnite tochki v masiva == " << AAcount(matrix, rows, cols) << endl;; break;
		case 9: 
			identitetCheck(matrix, rows, cols) ? cout << "Zapisanata v masiva permutaciq == id" << endl : cout << "Zapisanata v masiva permutaciq != id" << endl;; ; break;
		case 10: permutationCyclev2_print(matrix, cols);
			cout << endl;
			break;
		case 11: 
		{
			int* lengths = findPermutationCyclesLengthInArray(matrix, cols);
			cout << lengths[0] << " " << lengths[1] <<endl;
		}
		break;
		case 12: 
		{
			string str;
			cout << "Enter one cycled permutation." << endl;
			cin.ignore();
			getline(cin, str);
			cycleToTable(str);
		}break;

		case 13: compositionToTable();break;
		case 14: cout << reversePermutationv2() << endl;; break;
		case 15:
		{
			string str;
			cout << "Enter string" << endl;
			reverseComposeAndIdentityCheck(str, rows, cols); 
		}break;

		case 16: commutationCheck(); break;

		case 17:
		{
			string str;
			cout << "Enter string permutation:" << endl;
			cin >> str;
			cout << "Minimal i = " << iterationA(str) << endl;
		}break;
		case 18:
		{
			string str;
			cout << "Enter string permutation:" << endl;
			cin >> str;
			cout << "Minimal i = " << iterationB(str) << endl; 
		}break;
		default: cout << "No function selected. Try again." << endl;break;
		}
	}

	//OPERATIONS
	fill_array(matrix, rows, cols);
	log_array(matrix, rows, cols);
	bool isItInjective = checkInjectivePermutation(matrix, rows, cols);
	bool isItSurective = checkSurectivePermutation(matrix, rows, cols);
	bool isItPermutation = false;
	if (isItInjective && isItSurective)
		isItPermutation = true;
	int pN = permutationCount(cols);
	bool isThereAA = checkAA(matrix, rows, cols);
	int aacount;
	if (isThereAA)
	{
		aacount = AAcount(matrix, rows, cols);
	}
	bool identitetOrNot = identitetCheck(matrix, rows, cols);

	permutationCyclev2_print(matrix, cols);

	//GET CYCLE LENGTHS
	string line = permutationCyclev2_string(matrix, cols);
	int lineLength = line.length();
	int lengths[1001];

	int cnt = 0;
	int linePos = 0;
	for (size_t i = 0; i < lineLength-1; i++)
	{
		if (linePos >= lineLength-1)
			break;
		while (line[linePos] != ')')
		{
			cnt++;
			linePos++;
		}
		cnt--;
		linePos++;
		lengths[i] = cnt;
		cnt = 0;
	}

	//PRINT CYCLE LENGTHS

	for (size_t i = 0; i < 1000; i++)
	{
		if (lengths[i] < 0)
			break;
		else
			cout << "Length " << i << " == " << lengths[i] << endl;
	}

	int** table = cycleToTable(line);

	//LOG TABLE
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if(table[i][j] > 0)
				cout << table[i][j] << " ";
		}
		cout << endl;
	}

	int** compTable = compositionToTable();
	string reversedPer = reversePermutationv2();
	cout << reversedPer << endl;

	std::string RCIf = "(3 2 1)(5 4)";
	reverseComposeAndIdentityCheck(RCIf, rows, cols);


	//FREE MEMORY
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
