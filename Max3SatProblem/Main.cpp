#include "CGAOptimizer.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

srand(time(NULL));

string nazwaPliku;
int liczbaZmiennych;
int liczbaOsobnikow; // najlepiej ilosc osobnikow == 300, ale dla ulatwienia 100
int liczbaPopulacji; // najlepiej i <= 500
double probMutation;
double probCrossover;

cout << "Podaj nazwe pliku (z koncowka .txt): "; // z koncowka *.txt, tutaj plik4.txt
cin >> nazwaPliku;
cout << "Podaj liczbe zmiennych: "; // tutaj 350
cin >> liczbaZmiennych;
cout << "Podaj liczbe osobnikow: ";
cin >> liczbaOsobnikow;
cout << "Podaj liczbe populacji: ";
cin >> liczbaPopulacji;
cout << "Podaj prawdopodobienstwo krzyzowania: "; // najlepiej 0.80
cin >> probCrossover;
cout << "Podaj prawdopowobienstwo mutacji: "; // najlepiej 0.001
cin >> probMutation;

CGAOptimizer* optimizer = new CGAOptimizer(liczbaOsobnikow, probCrossover, probMutation); // najlepiej ilosc osobnikow == 300

if (optimizer->Initialize(liczbaZmiennych, nazwaPliku)) {

	for (int i = 0; i < liczbaPopulacji; i++) { // najlepiej i <= 500

		optimizer->runIteration();

	}

	optimizer->printBest();
}
	delete optimizer;
	return 0;
}