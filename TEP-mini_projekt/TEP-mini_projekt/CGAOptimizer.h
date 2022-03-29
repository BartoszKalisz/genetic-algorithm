#pragma once
#include <vector>
#include <string>
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
using namespace std;

class CGAOptimizer
{
public:
	CMax3SatProblem start;
	vector<CGAIndividual> Lista_osobnikow;
	int Prawd_mutacji;
	int Prawd_krzyzowania;
	int Wielkosc_populacji;
	int max;

	CGAOptimizer(int prawd_mutacji, int prawd_krzyzowania, int wielkosc_populacji);
	~CGAOptimizer();
	void Initialize();
	void RunIteration();
	CGAIndividual wybor_rodzica();
	void zmiana_parametrow(int prawd_mutacji, int prawd_krzyzowania, int wielkosc_populacji);
	void wyswietl_osobniki();
	void najlepszy_osobnik();
};
