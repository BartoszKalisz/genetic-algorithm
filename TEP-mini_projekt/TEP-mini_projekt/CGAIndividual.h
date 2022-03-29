#pragma once
#include <vector>
#include <random>
#include <time.h>
#include "iostream"
using namespace std;

class CGAIndividual
{
public:
	vector<int> genotyp;
	int fitness;
	
	CGAIndividual();
	~CGAIndividual();
	void initialize(int max);
	void Crossover(CGAIndividual &rodzic2,CGAIndividual &dziecko1, CGAIndividual &dziecko2);
	int Fitness();
	void Mutation(int szansa_mutacji);
	void wyswietl_osobnika();
	bool operator <(const CGAIndividual& val) const {
		return fitness < val.fitness;
	}
};
