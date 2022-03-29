#include "CMax3SatProblem.h"
#include "CGAOptimizer.h"
#include <iostream>
using namespace std;
int rozmiar_populacji, prawdopodobienstwo_krzyzowania, prawdopodobienstwo_mutacji;

void ustawienia_prwadopodobienstw() {
    cout << "Podaj prawdopodobienstwo krzyzowania" << endl;
    cin >> prawdopodobienstwo_krzyzowania;
    while (prawdopodobienstwo_krzyzowania > 100 || prawdopodobienstwo_krzyzowania < 0)
    {
        cout << "Bledny zakres prawdopodobienstwa, podaj liczbe od 0 do 100! " << endl;
        cin >> prawdopodobienstwo_krzyzowania;
    }

    cout << "Podaj prawdopodobienstwo mutacji" << endl;
    cin >> prawdopodobienstwo_mutacji;
    while (prawdopodobienstwo_mutacji > 100 || prawdopodobienstwo_mutacji < 0)
    {
        cout << "Bledny zakres prawdopodobienstwa, podaj liczbe od 0 do 100! " << endl;
        cin >> prawdopodobienstwo_mutacji;
    }
}

void Menu()
{
    cout << "1: Zmien prawdopodobienstwo krzyzowania i mutacji" << endl;
    cout << "2: Utworz nowa populacje rozwiazan(RunIteration)" << endl;
    cout << "3: Wyswietl osobniki" << endl;
    cout << "4: Pokaz najlepszego osobnika" << endl;
    cout << "5: Zakoncz" << endl;
}

int main()
{
    srand(time(NULL));
    cout << "Podaj rozmiar populacji" << endl;
    cin >> rozmiar_populacji;
    ustawienia_prwadopodobienstw();

    CGAOptimizer populacja(prawdopodobienstwo_mutacji,prawdopodobienstwo_krzyzowania,rozmiar_populacji);

    int zmienna;
    bool pomocnicza = true;
    while (pomocnicza)
    {
        Menu();
        cin >> zmienna;
        switch (zmienna)
        {
        case 1:
            ustawienia_prwadopodobienstw();
            populacja.zmiana_parametrow(prawdopodobienstwo_mutacji, prawdopodobienstwo_krzyzowania, rozmiar_populacji);
            break;

        case 2:
            populacja.RunIteration();
            break;

        case 3:
            populacja.wyswietl_osobniki();
            break;

        case 4:
            populacja.najlepszy_osobnik();
            break;

        case 5:
            pomocnicza = false;
            break;

        default:
            cout << "Bledny numer operacji, wprowadz liczbe jeszce raz" << endl;
            break;
        }
    }
}


