#pragma once
#include "CMax3SatProblem.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


CMax3SatProblem::CMax3SatProblem() {
}

CMax3SatProblem::~CMax3SatProblem() {
}

bool CMax3SatProblem::Load(string sFileName) {

	ifstream m3sFile;
	m3sFile.open(sFileName, ios::in);

	if (!m3sFile) {
		cout << "Blad odczytu pliku!";
		return false;
	}

	//vector<int> entry;
	//dalczego float
	string parenthesis;
	float variable1;
	float variable2;
	float variable3;

	while (m3sFile >> parenthesis >> variable1 >> variable2 >> variable3 >> parenthesis) {

		if (variable1 == 0.0 && signbit(variable1)){

			clauses.push_back(INT_MAX);
			clauses.push_back(variable2);
			clauses.push_back(variable3);
		}
		else if (variable2 == 0.0 && signbit(variable2)) {

			clauses.push_back(variable1);
			clauses.push_back(INT_MAX);
			clauses.push_back(variable3);
		}
		else if (variable3 == 0.0 && signbit(variable3)) {

			clauses.push_back(variable1);
			clauses.push_back(variable2);
			clauses.push_back(INT_MAX);
		}
		else {

			clauses.push_back(variable1);
			clauses.push_back(variable2);
			clauses.push_back(variable3);	
		}
	}

	m3sFile.close();

	return true;
}

int CMax3SatProblem::Compute(vector<int>& genotype) {

	int satisfied = 0;
	//dlaczego +3
	for (int i = 0; i <= clauses.size() - 3; i += 3) {
	
		//cout << i << " ";
		int fulfil = 0;

		for (int j = 0; j < 3; j++) {
			
			int value = clauses.at(i + j);
			//cout << value << " ";;
					
			if (value < 0) {

				fulfil += (1 - genotype.at(value*(-1)));
				//cout << value << " ";;
			}
			else if (value == INT_MAX) {

				fulfil += (1 - genotype.at(0));
			}
			else {

				fulfil += genotype.at(value);
			}				
			
		}
		
		if (fulfil > 0) {

			satisfied++;
		}
	}
	
	return satisfied;
}