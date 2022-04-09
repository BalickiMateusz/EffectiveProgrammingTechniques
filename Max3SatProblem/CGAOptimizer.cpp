#pragma once
#include "CGAOptimizer.h"
#include "CMax3SatProblem.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

CGAOptimizer::CGAOptimizer(int setPopulationSize, double setCrossingProb, double setMutationProb) {

	populationSize = setPopulationSize;
	crossingProb = setCrossingProb;
	mutationProb = setMutationProb;
}

CGAOptimizer::~CGAOptimizer() {

	for (int i = 0; i < population.size(); ++i) {
		delete population.at(i);
	}
	for (int i = 0; i < bestIndividuals.size(); ++i) {
		delete bestIndividuals.at(i);
	}
}


bool CGAOptimizer::Initialize(int liczbaKlauzul, string nazwaPliku) {

	CMax3SatProblem *problem = new CMax3SatProblem();
	if((*problem).Load(nazwaPliku)){
	

	for (int i = 0; i < populationSize; i++) {

		vector<int> genotype;

		for (int j = 0; j < liczbaKlauzul; j++) {

			genotype.push_back(rand() % 2);
		}

		CGAIndividual* indv = new CGAIndividual(genotype, mutationProb, problem);
		population.push_back(indv);
	}

	bestIndividuals.push_back(new CGAIndividual(*findBestIndividual(population)));
	return true;
	}
	else {
		cout << "Initialization failed!";
		return false;
	}
}

void CGAOptimizer::runIteration() {

	vector<CGAIndividual*> newPopulation;

	while (newPopulation.size() < population.size()) {

		CGAIndividual* firstParent = chooseParent();
		CGAIndividual* secondParent = chooseParent();

		if (((double)(rand() % 1001) / 1000) < crossingProb) {

			vector <CGAIndividual*> children = firstParent->Crossover(secondParent);

			for (int i = 0; i < children.size(); i++) {

				children.at(i)->Mutation();
				newPopulation.push_back(children.at(i));
			}
		}
		else {

			CGAIndividual *child1 = new CGAIndividual(*firstParent);
			CGAIndividual *child2 = new CGAIndividual(*secondParent);

			//child1->Mutation();
			//child2->Mutation();

			newPopulation.push_back(child1);
			newPopulation.push_back(child2);
		}

	}

	for (int j = 0; j < population.size(); ++j) {
		delete population.at(j);
	}

	population = newPopulation;
	bestIndividuals.push_back(new CGAIndividual(*findBestIndividual(population)));
}

CGAIndividual* CGAOptimizer::findBestIndividual(vector <CGAIndividual*>& population) {

	CGAIndividual* best = population.at(0);

	for (int i = 1; i < population.size(); i++) {

		if (best->Fitness() < population.at(i)->Fitness()) {

			best = population.at(i);
		}
	}

	return best;
}

CGAIndividual* CGAOptimizer::chooseParent() {

	//srand(time(NULL));

	int firstPosition = rand() % populationSize;
	int secondPosition = rand() % populationSize;

	CGAIndividual *firstIndividual = population.at(rand() % populationSize);
	CGAIndividual *secondIndividual = population.at(rand() % populationSize);

	if (firstIndividual->Fitness() > secondIndividual->Fitness()) {

		return firstIndividual;
	}
	else {

		return secondIndividual;
	}
}

void CGAOptimizer::printBest() {

	for (int i = 0; i < bestIndividuals.size(); i++) {


		cout << i;
		bestIndividuals.at(i)->Print();
	}
}