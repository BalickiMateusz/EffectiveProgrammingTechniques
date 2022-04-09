#ifndef CMAX3SATPROBLEM_H
#define CMAX3SATPROBLEM_H

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CMax3SatProblem {

public:
	CMax3SatProblem();
	~CMax3SatProblem();

	bool Load(string sFileName);
	int Compute(vector<int> &varsValue);

private:
	vector<int> clauses;
};
#endif