#include "CMax3SatProblem.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include "CGAIndividual.h"
using namespace std;

CMax3SatProblem::CMax3SatProblem() {
	Load();
}

CMax3SatProblem::~CMax3SatProblem() {
	
}

bool CMax3SatProblem::Load() {

	Klauzula tymczasowa;
	maks = -2147483648;
	ifstream file;
	file.open("m3s_50_0.txt", ios::in);
	if (file.is_open()) {

		while (!file.eof()) {
			file.ignore(10, '(');
			file >> tymczasowa.pierwsza_zmienna;
			if (abs(tymczasowa.pierwsza_zmienna) > maks)maks = tymczasowa.pierwsza_zmienna;
			file >> tymczasowa.druga_zmienna;
			if (abs(tymczasowa.druga_zmienna) > maks)maks = tymczasowa.druga_zmienna;
			file >> tymczasowa.trzecia_zmienna;
			if (abs(tymczasowa.trzecia_zmienna) > maks)maks = tymczasowa.trzecia_zmienna;
			dane.push_back(tymczasowa);
			file.ignore(10,')');
		}
		
	}
	else {
		cout << "Nie udalo sie otworzyc pliku";
	}

	file.close();
	dane.pop_back();
	return true;
}

void CMax3SatProblem::Compute(CGAIndividual &osobnik)
{
    int licznik = 0;
	int pomocnicza;
	
	for (int i = 0; i < dane.size(); i++)
	{
		
		pomocnicza = 0;
		
			if (dane[i].pierwsza_zmienna < 0)
			{
				
				if (osobnik.genotyp[abs(dane[i].pierwsza_zmienna)] == 0)
				{
					//prawda
					licznik++;
					pomocnicza = 1;
				}
				
			}
			
			else {
				if (osobnik.genotyp[abs(dane[i].pierwsza_zmienna)] == 1)
				{
					//prawda
					licznik++;
					pomocnicza = 1;
				}
			}

			//druga zmienna
			if (pomocnicza==0)
			{
				
				if (dane[i].druga_zmienna < 0)
				{
					if (osobnik.genotyp[abs(dane[i].druga_zmienna)] == 0)
					{
						//prawda
						licznik++;
						pomocnicza = 1;
					}

				}
				else {
					if (osobnik.genotyp[abs(dane[i].druga_zmienna)] == 1)
					{
						//prawda
						licznik++;
						pomocnicza = 1;
					}
				}
			}
			
			//trzecia zmienna
			if (pomocnicza == 0)
			{
				
				if (dane[i].trzecia_zmienna < 0)
				{
					if (osobnik.genotyp[abs(dane[i].trzecia_zmienna)] == 0)
					{
						//prawda
						licznik++;
						pomocnicza = 1;
					}

				}
				else {
					if (osobnik.genotyp[abs(dane[i].trzecia_zmienna)] == 1)
					{
						//prawda
						licznik++;
						pomocnicza = 1;
					}
				}
			}
			
	}
	osobnik.fitness = licznik;
}