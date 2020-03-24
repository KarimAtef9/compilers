#include "header/DFA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;
#define MAX_LEN 100

DFA dfa;

char NFA_TranstionTable[MAX_LEN][MAX_LEN][MAX_LEN];
char DFA_TranstionTable[MAX_LEN][MAX_LEN][MAX_LEN];
char* intialState;
char* finalState;
int statesCount = 0;
int symbolsCount = 0;
int epsilonIndex;
int intialStateIndex;
int tempDFA_row = 0;
int numberOfStatesTemp = 1;
int numberOfStates = 0;


vector<std::string> markedStates;
vector<pair<char*, vector <std::string> > > closureStates;


DFA::DFA() {
	std::cout<<"DFA Constructor"<<std::endl;
}

DFA::~DFA() {
	// TODO Auto-generated destructor stub
}

void DFA::readParameters(char* start ,char* final ,char table[][MAX_LEN][MAX_LEN]){
	intialState = start;
	finalState = final;

	std::cout<<"Table Size: "<<sizeof(table)<<std::endl;
	std::cout<<"sizeof(table[0]) / sizeof(table[i][0]): "<<sizeof(table[0]) / sizeof(table[0][0])<<std::endl;

	for (int i = 0; i < MAX_LEN; i++){
		for (int j = 0; j < MAX_LEN; j++){
			strcpy(NFA_TranstionTable[i][j], table[i][j]);
		}
	}

	for (int i = 1; i < sizeof(table[0]) / sizeof(table[0][0]); i++){
		if (strcmp(table[i][0], "")){
			statesCount++;
		}
	}

	for (int i = 1; i < sizeof(table[i]) / sizeof(table[i][0]); i++){
		if (!strcmp(table[0][i], "epsilon")){
			continue;
		}else if (strcmp(table[0][i], "")){
			symbolsCount++;
		}
	}

	std::cout<<"symbolsCount: "<<symbolsCount<<std::endl;


	for (int i = 0; i < sizeof(table); i++){
		if (!strcmp(table[i][0], intialState)){
			std::cout<<"Table: "<<table[i][0]<<std::endl;
			int intialStateIndex = i;
			std::cout<<"intialStateIndex: "<<i<<std::endl;
		}
	}

	for (int i = 0; i < sizeof(table[0]); i++){
		if (!strcmp(table[0][i], "epsilon")){
			epsilonIndex = i;
			std::cout<<"epsilonIndex: "<<i<<std::endl;
		}
	}

	strcpy(DFA_TranstionTable[0][0], "States");
	for (int j = 1; j < symbolsCount+1; j++){
		if (!strcmp(table[0][j], "epsilon")){
			continue;
		} else{
			strcpy(DFA_TranstionTable[0][j], table[0][j]);
			//std::cout<<"DFA_TranstionTable[i][j]: "<<DFA_TranstionTable[0][j]<<std::endl;
		}
	}

	std::cout<<"NFA_TranstionTable[4][2] "<<NFA_TranstionTable[4][2]<<std::endl;



	std::cout<<"statesCount: "<<statesCount<<std::endl;

}

void DFA::convert(){

	for (int i = 0; i < statesCount; i++){
		epsilonClosure(i+1);
	}

	for (int i = 0; i < closureStates.size(); i++){
		std::cout<<"state: "<<closureStates[i].first <<std::endl;
		for (int j = 0; j < closureStates[i].second.size(); j++){
			std::cout<<"Closure: "<<closureStates[i].second[j] <<" "<<std::endl;
		}

	}




	vector<std::string> intialEpsilonClosure = dfa.firstEpsilonClosure(intialState);
	dfa.transition(intialEpsilonClosure);
	numberOfStates++;

	std::cout<<" "<<std::endl;
	std::cout<<"**THE NEWSTATES**"<<std::endl;

	int tempRow = tempDFA_row;
	while (numberOfStatesTemp > 0){

		for (int i = 1; i < symbolsCount+1; i++){
			std::cout<<"DFA: "<<DFA_TranstionTable[tempRow][i]<<std::endl;

			std::string tempState = DFA_TranstionTable[tempRow][i];
			std::cout<<"tempState: "<<tempState<<std::endl;

			for (int g = 0; g < markedStates.size(); g++){
				std::cout << "markedStates "<<markedStates[g]<<std::endl;
			}

			if (!(std::count(markedStates.begin(), markedStates.end(), tempState))){
				std::cout << "Element Not Found"<<std::endl;
				numberOfStates++;
				char* tempStateChar = const_cast<char*>(tempState.c_str());

				vector<std::string> tempStateArr;

				for(int j = 0; j < strlen(tempStateChar); j++){
					std::string s(1, tempStateChar[j]);
					char* charNextState = const_cast<char*>(s.c_str());
					std::string x = charNextState;

					tempStateArr.push_back(x);
				}
				dfa.transition(tempStateArr);
			}
		}
		tempRow++;
		numberOfStatesTemp--;
	}
	dfa.displayDFA_TransitionTAble();

}

void DFA::epsilonClosure(int i){
	std::cout<<" "<<std::endl;
	std::cout<<"**epsilonClosure Function**"<<std::endl;
	std::cout<<"CurrentState: "<<NFA_TranstionTable[i][0]<<std::endl;

    stack <int> stack;
    pair<char*, vector <std::string> > closure;

    closure.first = NFA_TranstionTable[i][0];
    closure.second.push_back(NFA_TranstionTable[i][0]);

	stack.push(i);

	while(!stack.empty()){
		int currentState = stack.top();
		stack.pop();

		if(strcmp(NFA_TranstionTable[currentState][epsilonIndex], "-")){
			char* nextState = NFA_TranstionTable[currentState][epsilonIndex];

			std::cout<<"strlen(nextState): "<<strlen(nextState)<<std::endl;

			for (int t = 0; t < strlen(nextState); t++){
				// Convert char to char*
				std::string s(1, nextState[t]);
				char* charNextState = const_cast<char*>(s.c_str());

				std::string str = charNextState;

			    closure.second.push_back(str);

				std::cout<<"charNextState: "<<nextState[t]<<std::endl;
				//std::cout<<"NFA_TranstionTable Size: "<<sizeof(NFA_TranstionTable)/sizeof(NFA_TranstionTable[0])<<std::endl;

				for (int j = 1; j < sizeof(NFA_TranstionTable)/sizeof(NFA_TranstionTable[0]); j++){

					if (!strcmp(NFA_TranstionTable[j][0], charNextState)){
						stack.push(j);
						std::cout<<"Push In The Stack: "<<j<<std::endl;
					}
				}
			}
		}
	}

	closureStates.push_back(closure);
}


vector <std::string> DFA::firstEpsilonClosure(char* initState){
	std::cout<<" "<<std::endl;
	std::cout<<"**transition Function**"<<std::endl;
	vector <std::string> intialClosure;

	/* Get the Epsilon Closure of the intial State */
	for (int i = 0; i < closureStates.size(); i++){
		//std::cout<<"State: "<<closureStates[i].first<<std::endl;
		if (! strcmp(closureStates[i].first, initState)){
			intialClosure = closureStates[i].second;
		}
		for (int j = 0; j < closureStates[i].second.size(); j++){
			//std::cout<<"TheirClosures: "<<closureStates[i].second[j]<<std::endl;
		}
	}

	return intialClosure;
}

void DFA::transition(vector <std::string> set){

	std::cout<<" "<<std::endl;
	std::cout<<"Transition Function: "<<std::endl;
	/* Get the Transitions of each state in the Set */
	std::string tempS;
	for (int n = 0; n < set.size(); n++){
		tempS = tempS + set[n];
	}
	markedStates.push_back(tempS);

	tempDFA_row++;
	for (int i = 1; i < symbolsCount+1; i++){
		std::cout<<"NewSymbol: "<<DFA_TranstionTable[0][i]<<"<<"<<std::endl;
		vector <std::string> resultWithoutClosure;
		std::string tempState;
		for (int j = 0; j < set.size(); j++){
			tempState = tempState + set[j];

			char* tempSymbol =	const_cast<char*>(set[j].c_str());
			std::cout<<"tempSymbol: "<<tempSymbol<<std::endl;
			int tempSymbolIndex;
			for (int t = 1; t < sizeof(NFA_TranstionTable)/sizeof(NFA_TranstionTable[0]); t++){
				if (!strcmp(NFA_TranstionTable[t][0], tempSymbol)){
					tempSymbolIndex = t;
					std::cout<<"Symbol Index: "<<t<<std::endl;
					break;
				}
			}
			if (strcmp(NFA_TranstionTable[tempSymbolIndex][i], "-")){
				resultWithoutClosure.push_back(NFA_TranstionTable[tempSymbolIndex][i]);
			} else {
				std::cout<<"Corresponding Value= -"<<std::endl;
				continue;
			}
		}

		for (int f = 0; f < resultWithoutClosure.size(); f++){
			std::cout<<"resultWithoutClosure: "<<resultWithoutClosure[f]<<std::endl;
			std::cout<<" "<<std::endl;
		}

		strcpy(DFA_TranstionTable[tempDFA_row][0], const_cast<char*>(tempState.c_str()));

		std::string temp;
		for (int f = 0; f < resultWithoutClosure.size(); f++){
			std::cout<<"result: "<<resultWithoutClosure[f]<<std::endl;
			temp = temp + resultWithoutClosure[f];
		}
		strcpy(DFA_TranstionTable[tempDFA_row][i], const_cast<char*>(temp.c_str()));

		for (int h = 0; h < symbolsCount+1; h++){
			std::cout<<"DFA: "<<DFA_TranstionTable[tempDFA_row][h]<<std::endl;
		}

		dfa.unionClosure(tempDFA_row, i);

		for (int h = 0; h < symbolsCount+1; h++){
			std::cout<<"DFA: "<<DFA_TranstionTable[tempDFA_row][h]<<std::endl;
		}



		std::string checkExist = DFA_TranstionTable[tempDFA_row][i];
		if(!(std::count(markedStates.begin(), markedStates.end(), checkExist))){
			std::cout << "Element Not Found"<<std::endl;
			numberOfStatesTemp++;
		}
	}

}

/*void DFA::getNewStates(){

}*/

void DFA::unionClosure(int tempRow, int tempColumn){
	std::cout<<" "<<std::endl;
	std::cout<<"**unionClosure Function**"<<std::endl;


	std::string currentTransition = DFA_TranstionTable[tempRow][tempColumn];
	std::cout<<"currentTransition: "<<currentTransition<<std::endl;

	char* currentTransitionArr = const_cast<char*>(currentTransition.c_str());

	std::string unionTrans;

	for (int j = 0; j < strlen(currentTransitionArr); j++){
		std::string newTransition;

		std::string s(1, currentTransitionArr[j]);
		char* tempNewTransition = const_cast<char*>(s.c_str());

		newTransition = newTransition + currentTransitionArr[j];

		for(int t = 0; t < closureStates.size();t++){
			if(! strcmp(closureStates[t].first, tempNewTransition) ){
				std::string stateClosure;
				for(int u = 0; u < closureStates[t].second.size(); u++){
					stateClosure = stateClosure + closureStates[t].second[u];
				}
				newTransition = newTransition + stateClosure;
			}
		}
		unionTrans = unionTrans + newTransition;
	}
	std::cout<<"unionTrans: "<<unionTrans<<std::endl;
	std::string finalUnionTransistion = removeDuplicate(unionTrans);
	std::cout<<"finalUnionTransistion: "<<finalUnionTransistion<<std::endl;
	sort(finalUnionTransistion.begin(), finalUnionTransistion.end());
	std::cout<<"finalUnionTransistion: "<<finalUnionTransistion<<std::endl;

	strcpy(DFA_TranstionTable[tempRow][tempColumn], const_cast<char*>(finalUnionTransistion.c_str()));

}

std::string DFA::removeDuplicate(std::string str) {

	 // keeps track of visited characters
	 int counter = 0;
	 int i = 0;
	 int size = str.size();

	 // gets character value
	 int x;
	 // keeps track of length of resultant string
	 int length = 0;
	 while (i < size) {
		 x = str[i] - 97;
	     // check if Xth bit of counter is unset
	     if ((counter & (1 << x)) == 0) {
	    	 str[length] = 'a' + x;
	         // mark current character as visited
	         counter = counter | (1 << x);
	         length++;
	     }
	     i++;
	 }
	 return str.substr(0, length);
}



void DFA::displayDFA_TransitionTAble(){
	std::cout<<"**DFA TRANSITION TABLE**"<<std::endl;

	for (int i = 0; i < numberOfStates+1; i++){
		for (int j = 0; j < symbolsCount+1; j++){
			std::cout<<"DFA"<<"["<<i<<"]"<<"["<<j<<"]: "<<DFA_TranstionTable[i][j]<<std::endl;
		}
	}
}



