#ifndef _array_functions_
#define _array_functions_
#include <string>

int fill_array(int**, unsigned, unsigned);
int log_array(int**, unsigned, unsigned);
bool checkInjectivePermutation(int**, unsigned, unsigned);
bool checkSurectivePermutation(int**, unsigned, unsigned);
int permutationCount(unsigned);
bool checkAA(int**, unsigned, unsigned);
int AAcount(int**, unsigned, unsigned);
bool identitetCheck(int**, unsigned, unsigned);
std::string permutationCycle(int**, unsigned);
int** permutationCyclev2_print(int**, unsigned);
int* findPermutationCyclesLengthInArray(int**, unsigned);
bool checkIfAdded(int*, int, int);
int getCycleLength(int*);
int* getCycle(int*, int*, int);
std::string permutationCyclev2_string(int**, unsigned);
int** cycleToTable(std::string);
int** compositionToTable();
std::string reversePermutation(std::string);
std::string reversePermutationv2();
void reverseComposeAndIdentityCheck(std::string, unsigned, unsigned);
int commutationCheck();
int iterationA(std::string);
std::string compositionReworkv2(std::string);
int iterationB(std::string);
#endif
