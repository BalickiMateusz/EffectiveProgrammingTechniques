#ifndef CGAOPTIMIZER_H
#define CGAOPTIMIZER_H

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CGAIndividual.h"
using namespace std;

class CGAOptimizer {
	
public:
	CGAOptimizer(int populationSizel, double crossingProb, double mutationProb);
	~CGAOptimizer();

	bool Initialize(int liczbaKlauzul, string nazwaPliku);
	void runIteration();
	CGAIndividual* chooseParent();
	CGAIndividual* findBestIndividual(vector <CGAIndividual*>& population);
	void printBest();

private:
	int populationSize;
	double crossingProb;
	double mutationProb;
	vector<CGAIndividual*> population;
	vector<CGAIndividual*> bestIndividuals;
};
#endif