#include "CTable.h"
#include <iostream>
using namespace std;

void v_lista_1() {

	//Dynamiczna alokacja obiektow
	CTable* pc_tab_1, * pc_tab_2, * pc_tab_3, * pc_tab_4;

	//Konstruktor bezparametrowy
	pc_tab_1 = new CTable();

	cout << "\nObject pc_tab_1: \n";
	cout << "Name: " << pc_tab_1->sGetTableName() << "\n";;
	cout << "Array length: " << pc_tab_1->iGetTableLen() << "\n";;

	//Metoda vSetName
	pc_tab_1->vSetName("pc_tab_1");

	//Metoda bSetNewSize
	pc_tab_1->bSetNewSize(5);

	cout << "\nObject pc_tab_1 after change: \n";
	cout << "Name: " << pc_tab_1->sGetTableName() << "\n";
	cout << "Array length: " << pc_tab_1->iGetTableLen() << "\n";

	//Konstruktor z parametrem
	pc_tab_2 = new CTable("pc_tab_2", 10);

	cout << "\nObject pc_tab_2: \n";
	cout << "Name: " << pc_tab_2->sGetTableName() << "\n";
	cout << "Array length: " << pc_tab_2->iGetTableLen() << "\n";

	//Konstruktor kopiuj¹cy
	pc_tab_3 = new CTable(*pc_tab_1);

	cout << "\nObject pc_tab_3: \n";
	cout << "Name: " << pc_tab_3->sGetTableName() << "\n";
	cout << "Array length: " << pc_tab_3->iGetTableLen() << "\n";

	//Metoda *pcClone()
	pc_tab_4 = pc_tab_2->pcClone();

	cout << "\nObject pc_tab_4: \n";
	cout << "Name: " << pc_tab_4->sGetTableName() << "\n";
	cout << "Array length: " << pc_tab_4->iGetTableLen() << "\n";

	//Statyczna alokacja obiektu, konstruktor bezparametrowy
	CTable c_tab_5;

	cout << "\nObject c_tab_5: \n";
	cout << "Name: " << c_tab_5.sGetTableName() << "\n";;
	cout << "Array length: " << c_tab_5.iGetTableLen() << "\n";;

	//Procedura v_mod_tab(CTable* pcTab, int iNewSize)
	v_mod_tab(&c_tab_5, 4);

	cout << "\nObject c_tab_5 after calling v_mod_tab(CTable* pcTab, int iNewSize): \n";
	cout << "Name: " << c_tab_5.sGetTableName() << "\n";;
	cout << "Array length: " << c_tab_5.iGetTableLen() << "\n";;

	//Procedura v_mod_tab(CTable pcTab, int iNewSize)
	v_mod_tab(c_tab_5, 7);

	cout << "\nObject c_tab_5 after calling v_mod_tab(CTable pcTab, int iNewSize): \n";
	cout << "Name: " << c_tab_5.sGetTableName() << "\n";;
	cout << "Array length: " << c_tab_5.iGetTableLen() << "\n";;

	//Alokacja tablicy obiektow
	CTable* pc_tab_tab;
	pc_tab_tab = new CTable[4];

	//Destruktor
	delete pc_tab_1;
	delete pc_tab_2;
	delete pc_tab_3;
	delete pc_tab_4;
	delete[] pc_tab_tab;
}

void v_lista_2(){

	/*
	//Zadanie 1
	//Tworzymy c_tab_0, c_tab_1. Nastêpnie za pomoc¹ operator= sprawiamy, ¿e c_tab_0.pi_table oraz c_tab_1.pi_table wskazuj¹ na ten sam obszar w pamiêci. 
	//Na koniec programu uruchamiane s¹ destruktory: najpierw usuwany jest c_tab_1, nastêpnie nastêpuje próba usuniêcia c_tab_0 - jednak obszar pamiêci na który wskazuje c_tab_0.pi_table jest ju¿ zwolniony. 
	//Powoduje to b³¹d (dwukrotna próba zwolnienia tej samej pamiêci).
	CTable  c_tab_0, c_tab_1;

	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);

	c_tab_0 = c_tab_1;
	*/

	//Zadanie 2
	//Po usuniêciu destruktora z klasy CTable nie nastêpuje próba usuniêcia obiektów c_tab_0 oraz c_tab_1. W zwi¹zku z tym, nie mamy b³êdu z æwiczenia 1 - jednak nastêpuje wyciek pamiêci.

	
	
	//Zadanie 3
	CTable  c_tab_0, c_tab_1;

	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);

	//Wpisanie wartosci do tablic

	for (int i = 0; i < c_tab_0.iGetTableLen(); i++) {

		c_tab_0.vSetValueAt(i, i+1);
	}

	for (int j = 0; j < c_tab_1.iGetTableLen(); j++) {

		c_tab_1.vSetValueAt(j, j + 50);
	}

	c_tab_0 = c_tab_1;

	c_tab_1.vSetValueAt(2, 123);


	//Wypisanie tablic na ekran
	cout << "\nObject c_tab_0: \n";
	c_tab_0.vPrint();

	cout << "\nObject c_tab_1: \n";
	c_tab_1.vPrint();
	
	
	//Zadanie 4: operator+ zwaracj¹cy konkatenacjê dwóch tablic
	CTable c_tab_2 = c_tab_0 + c_tab_1;

	cout << "\nObject c_tab_2: \n";
	c_tab_2.vPrint();
	
}

int main() {

	//v_lista_1();
	v_lista_2();
	return 0;
}
