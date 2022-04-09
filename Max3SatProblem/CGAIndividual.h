#ifndef CGAINDIVIDUAL_H
#define CGAINDIVIDUAL_H

#pragma once
#include <iostream>
#include <vector>
#include "CMax3SatProblem.h"

#define PROBABILITY_OF_SWAP 0.5;

using namespace std;

class CGAIndividual {

public:
	CGAIndividual(vector<int> genotype, double &mutationProbability, CMax3SatProblem* m3sProblem);
	CGAIndividual(CGAIndividual &cOther);
	~CGAIndividual();
	vector<CGAIndividual*> Crossover(CGAIndividual* cOther);
	void Mutation();
	int Fitness();
	void Print();

private:
	int fitness;
	vector<int> genotype;
	double mutationProbability;
	CMax3SatProblem* m3sProblem;
};
#endif