#pragma once
#include "CGAIndividual.h"
#include <iostream>
#include <vector>
using namespace std;

CGAIndividual::CGAIndividual(vector<int> setGenotype, double& setMutationProbability, CMax3SatProblem* setM3sProblem) {

	genotype = setGenotype;
	mutationProbability = setMutationProbability;
	m3sProblem = setM3sProblem;
}

CGAIndividual::CGAIndividual(CGAIndividual &cOther) {

	genotype = cOther.genotype;
	mutationProbability = cOther.mutationProbability;
	fitness = cOther.fitness;
	m3sProblem = cOther.m3sProblem;
}

CGAIndividual::~CGAIndividual() {
}

vector<CGAIndividual*> CGAIndividual::Crossover(CGAIndividual* cOther) {

	vector<int> firstGenotype;
	vector<int> secondGenotype;

	double x = PROBABILITY_OF_SWAP;

	//srand(time(NULL));

	for (int i = 0; i < genotype.size(); i++) {

		double drawParent = (double) (rand() % 101) / 100;

		if (drawParent <= x) {

			firstGenotype.push_back(cOther->genotype.at(i));
			secondGenotype.push_back(genotype.at(i));
		}
		else {

			firstGenotype.push_back(genotype.at(i));
			secondGenotype.push_back(cOther->genotype.at(i));
		}
	}

	CGAIndividual* firstChild = new CGAIndividual(firstGenotype, mutationProbability, m3sProblem);
	CGAIndividual* secondChild = new CGAIndividual(secondGenotype, mutationProbability, m3sProblem);

	vector<CGAIndividual*> children;
	children.push_back(firstChild);
	children.push_back(secondChild);

	return children;
}

void CGAIndividual::Mutation() {

	//srand(time(NULL));

	for (int i = 0; i < genotype.size(); i++) {

		if ((double)(rand() % 10001) / 10000 < mutationProbability) {

			genotype.at(i) = 1 - genotype.at(i);
		}
	}
}

int CGAIndividual::Fitness() {

	fitness = m3sProblem->Compute(genotype);
	return fitness;
}

void CGAIndividual::Print() {

	cout << "Genotyp: ";

	for (int i = 0; i < genotype.size(); i++) {

		cout << genotype.at(i);
	}

	cout << endl << "Fitness: " << fitness << endl;
}