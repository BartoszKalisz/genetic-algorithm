#include "CGAIndividual.h"
using namespace std;

CGAIndividual::CGAIndividual() {
	fitness = 0;
}
CGAIndividual::~CGAIndividual() {

}
void CGAIndividual::initialize(int max) {
	
	for (int i = 0; i <=max; i++)
	{
		genotyp.push_back(rand() % (2));
	}
	
}
int CGAIndividual::Fitness()
{
	return fitness;
}
void CGAIndividual::Crossover(CGAIndividual &rodzic2,CGAIndividual &dziecko1,CGAIndividual &dziecko2)
{
	for (int i = 0; i < genotyp.size(); i++)
	{
		if (rand() % 2 == 0)
		{
			dziecko1.genotyp.push_back(genotyp[i]);
			dziecko2.genotyp.push_back(rodzic2.genotyp[i]);
		}
		else {
			dziecko2.genotyp.push_back(genotyp[i]);
			dziecko1.genotyp.push_back(rodzic2.genotyp[i]);
		}
	}
}
void CGAIndividual::Mutation(int szansa_mutacji)
{
	for (int i = 0; i < genotyp.size(); i++)
	{
		if (rand() % 101 < szansa_mutacji)
		{
			if (genotyp[i] == 1) genotyp[i] = 0;
			else genotyp[i] = 1;
		}
	}
}
void CGAIndividual::wyswietl_osobnika()
{
	for (int j = 0; j <genotyp.size(); j++)
	{
		cout << genotyp[j];
	}
}