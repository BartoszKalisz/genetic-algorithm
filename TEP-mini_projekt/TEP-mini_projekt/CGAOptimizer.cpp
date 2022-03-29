#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer(int prawd_mutacji, int prawd_krzyzowania,int wielkosc_populacji) {
	Prawd_krzyzowania = prawd_krzyzowania;
	Prawd_mutacji = prawd_mutacji;
	Wielkosc_populacji = wielkosc_populacji;

	max = start.maks;

	for (int i = 0; i < Wielkosc_populacji; i++)
	{
		CGAIndividual nowy_osobnik;
		Lista_osobnikow.push_back(nowy_osobnik);
	}
	Initialize();
}
CGAOptimizer::~CGAOptimizer() {

}
void CGAOptimizer::Initialize() {
	
	for (int i = 0; i < Lista_osobnikow.size(); i++)
	{
		Lista_osobnikow[i].initialize(max);
		
	}
}
void CGAOptimizer::RunIteration() {
	vector<CGAIndividual> nowa_Lista_osobnikow;
	CGAIndividual rodzic1;
	CGAIndividual rodzic2;
	CGAIndividual dziecko1;
	CGAIndividual dziecko2;

	for (int i = 0; i < Lista_osobnikow.size(); i++)
	{
		start.Compute(Lista_osobnikow[i]);
		
	}

	while (nowa_Lista_osobnikow.size()<Lista_osobnikow.size())
	{
		rodzic1 = wybor_rodzica();
		rodzic2 = wybor_rodzica();
		int x = rand() % 101;
		if (x < Prawd_krzyzowania) {
			rodzic1.Crossover(rodzic2, dziecko1, dziecko2); 
		}
		
			dziecko1 = rodzic1;
			dziecko2 = rodzic2;
		
		dziecko1.Mutation(Prawd_mutacji);
		dziecko2.Mutation(Prawd_mutacji);

		nowa_Lista_osobnikow.push_back(dziecko1);
		nowa_Lista_osobnikow.push_back(dziecko2);
	}
	Lista_osobnikow = nowa_Lista_osobnikow;
}
CGAIndividual CGAOptimizer::wybor_rodzica()
{
	CGAIndividual kandydat1;
	CGAIndividual kandydat2;
	kandydat1 = Lista_osobnikow[rand() % Lista_osobnikow.size()];
	kandydat2 = Lista_osobnikow[rand() % Lista_osobnikow.size()];
	if (kandydat1.fitness > kandydat2.fitness) return kandydat1;
	else return kandydat2;
}

void CGAOptimizer::zmiana_parametrow(int prawd_mutacji, int prawd_krzyzowania, int wielkosc_populacji)
{
	Prawd_krzyzowania = prawd_krzyzowania;
	Prawd_mutacji = prawd_mutacji;
	Wielkosc_populacji = wielkosc_populacji;
}

void CGAOptimizer::wyswietl_osobniki()
{
	for (int i = 0; i < Lista_osobnikow.size(); i++)
	{
		Lista_osobnikow[i].wyswietl_osobnika();
		cout << endl;
	}
}

void CGAOptimizer::najlepszy_osobnik()
{
	for (int i = 0; i < Lista_osobnikow.size(); i++)
	{
		start.Compute(Lista_osobnikow[i]);
		
	}
	sort(Lista_osobnikow.begin(), Lista_osobnikow.end());
	Lista_osobnikow[Lista_osobnikow.size() - 1].wyswietl_osobnika();
	cout << endl << "Wynik: " << Lista_osobnikow[Lista_osobnikow.size() - 1].fitness<<endl;
}