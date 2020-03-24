#include <iostream>

#include "lexical/header/lexicalGenerator.h"
#include "lexical/header/DFA.h"
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 100


int main() {
	// phase 1
	lexicalGenerator lex;

	char NFA_TranstionTable[MAX_LEN][MAX_LEN][MAX_LEN];

	char* intialState;
	char* finalState;

	intialState = "A";
	finalState = "C";


	/*strcpy(NFA_TranstionTable[0][0], "states");
	strcpy(NFA_TranstionTable[0][1], "0");
	strcpy(NFA_TranstionTable[0][2], "1");
	strcpy(NFA_TranstionTable[0][3], "epsilon");
	strcpy(NFA_TranstionTable[1][0], "A");
	strcpy(NFA_TranstionTable[1][1], "BC");
	strcpy(NFA_TranstionTable[1][2], "A");
	strcpy(NFA_TranstionTable[1][3], "B");
	strcpy(NFA_TranstionTable[2][0], "B");
	strcpy(NFA_TranstionTable[2][1], "-");
	strcpy(NFA_TranstionTable[2][2], "B");
	strcpy(NFA_TranstionTable[2][3], "C");
	strcpy(NFA_TranstionTable[3][0], "C");
	strcpy(NFA_TranstionTable[3][1], "C");
	strcpy(NFA_TranstionTable[3][2], "C");
	strcpy(NFA_TranstionTable[3][3], "-");*/

	/*strcpy(NFA_TranstionTable[0][0], "states");
	strcpy(NFA_TranstionTable[0][1], "0");
	strcpy(NFA_TranstionTable[0][2], "1");
	strcpy(NFA_TranstionTable[0][3], "epsilon");
	strcpy(NFA_TranstionTable[1][0], "A");
	strcpy(NFA_TranstionTable[1][1], "FC");
	strcpy(NFA_TranstionTable[1][2], "-");
	strcpy(NFA_TranstionTable[1][3], "BF");
	strcpy(NFA_TranstionTable[2][0], "B");
	strcpy(NFA_TranstionTable[2][1], "-");
	strcpy(NFA_TranstionTable[2][2], "C");
	strcpy(NFA_TranstionTable[2][3], "-");
	strcpy(NFA_TranstionTable[3][0], "C");
	strcpy(NFA_TranstionTable[3][1], "-");
	strcpy(NFA_TranstionTable[3][2], "-");
	strcpy(NFA_TranstionTable[3][3], "D");
	strcpy(NFA_TranstionTable[4][0], "D");
	strcpy(NFA_TranstionTable[4][1], "E");
	strcpy(NFA_TranstionTable[4][2], "A");
	strcpy(NFA_TranstionTable[4][3], "-");
	strcpy(NFA_TranstionTable[5][0], "E");
	strcpy(NFA_TranstionTable[5][1], "A");
	strcpy(NFA_TranstionTable[5][2], "-");
	strcpy(NFA_TranstionTable[5][3], "BF");
	strcpy(NFA_TranstionTable[6][0], "F");
	strcpy(NFA_TranstionTable[6][1], "-");
	strcpy(NFA_TranstionTable[6][2], "-");
	strcpy(NFA_TranstionTable[6][3], "-");*/

	strcpy(NFA_TranstionTable[0][0], "states");
	strcpy(NFA_TranstionTable[0][1], "0");
	strcpy(NFA_TranstionTable[0][2], "1");
	strcpy(NFA_TranstionTable[0][3], "epsilon");
	strcpy(NFA_TranstionTable[1][0], "A");
	strcpy(NFA_TranstionTable[1][1], "-");
	strcpy(NFA_TranstionTable[1][2], "-");
	strcpy(NFA_TranstionTable[1][3], "BH");
	strcpy(NFA_TranstionTable[2][0], "B");
	strcpy(NFA_TranstionTable[2][1], "-");
	strcpy(NFA_TranstionTable[2][2], "-");
	strcpy(NFA_TranstionTable[2][3], "CE");
	strcpy(NFA_TranstionTable[3][0], "C");
	strcpy(NFA_TranstionTable[3][1], "D");
	strcpy(NFA_TranstionTable[3][2], "-");
	strcpy(NFA_TranstionTable[3][3], "-");
	strcpy(NFA_TranstionTable[4][0], "D");
	strcpy(NFA_TranstionTable[4][1], "-");
	strcpy(NFA_TranstionTable[4][2], "-");
	strcpy(NFA_TranstionTable[4][3], "G");
	strcpy(NFA_TranstionTable[5][0], "E");
	strcpy(NFA_TranstionTable[5][1], "-");
	strcpy(NFA_TranstionTable[5][2], "F");
	strcpy(NFA_TranstionTable[5][3], "-");
	strcpy(NFA_TranstionTable[6][0], "F");
	strcpy(NFA_TranstionTable[6][1], "-");
	strcpy(NFA_TranstionTable[6][2], "-");
	strcpy(NFA_TranstionTable[6][3], "G");
	strcpy(NFA_TranstionTable[7][0], "G");
	strcpy(NFA_TranstionTable[7][1], "-");
	strcpy(NFA_TranstionTable[7][2], "-");
	strcpy(NFA_TranstionTable[7][3], "BH");
	strcpy(NFA_TranstionTable[8][0], "H");
	strcpy(NFA_TranstionTable[8][1], "I");
	strcpy(NFA_TranstionTable[8][2], "-");
	strcpy(NFA_TranstionTable[8][3], "-");
	strcpy(NFA_TranstionTable[9][0], "I");
	strcpy(NFA_TranstionTable[9][1], "-");
	strcpy(NFA_TranstionTable[9][2], "-");
	strcpy(NFA_TranstionTable[9][3], "-");

	//Convert String to Char*
	/*std::string x = "5";
	std::string y = "5";

	char* xChar = const_cast<char*>(x.c_str());
	char* yChar = const_cast<char*>(y.c_str());


	if (!strcmp(xChar, yChar)){
		std::cout<<"EQUAL"<<std::endl;
	}*/




	DFA dfa;
	dfa.readParameters(intialState, finalState, NFA_TranstionTable);
	dfa.convert();

	return 0;
}
