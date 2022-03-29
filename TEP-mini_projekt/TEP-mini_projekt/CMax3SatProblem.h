#pragma once
#include <vector>
#include <string>
#include "CGAIndividual.h"
using namespace std;

struct Klauzula {
	int pierwsza_zmienna;
	int druga_zmienna;
	int trzecia_zmienna;
};

class CMax3SatProblem
{
public:
	vector <Klauzula> dane;
	int maks;

	CMax3SatProblem();
	~CMax3SatProblem();
	bool Load();
	void Compute(CGAIndividual &osobnik);
	
};

