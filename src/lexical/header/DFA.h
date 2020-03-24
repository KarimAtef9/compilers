#ifndef LEXICAL_HEADER_DFA_H_
#define LEXICAL_HEADER_DFA_H_
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
#define MAX_LEN 100

class DFA {
public:
	DFA();
	virtual ~DFA();
	void readParameters(char* ,char* , char [][MAX_LEN][MAX_LEN]);
	void convert();
	void epsilonClosure(int);
	vector<std::string> firstEpsilonClosure(char*);
	void transition(vector <std::string>);
	void unionClosure(int, int);
	std::string removeDuplicate(std::string);
	void displayDFA_TransitionTAble();



};

#endif /* LEXICAL_HEADER_DFA_H_ */
