#include "CTable.h"
#include <iostream>
using namespace std;

int main() {

	//Dynamiczna alokacja obiektow
	CTable* pc_table_one, * pc_table_two, *pc_table_three, *pc_table_four;

	//Konstruktor bezparametrowy
	pc_table_one = new CTable();

	cout << "\nObject pc_table_one: \n";
	cout << "Name: " << pc_table_one->sGetTableName() << "\n";;
	cout << "Array length: " << pc_table_one->iGetTableLen() << "\n";;

	//Metoda vSetName
	pc_table_one->vSetName("pc_table_one");

	//Metoda bSetNewSize
	pc_table_one->bSetNewSize(5);

	cout << "\nObject pc_table_one after change: \n";
	cout << "Name: " << pc_table_one->sGetTableName() << "\n";
	cout << "Array length: " << pc_table_one->iGetTableLen() << "\n";

	//Konstruktor z parametrem
	pc_table_two = new CTable("pc_table_two", 10);

	cout << "\nObject pc_table_two: \n";
	cout << "Name: " << pc_table_two->sGetTableName() << "\n";
	cout << "Array length: " << pc_table_two->iGetTableLen() << "\n";

	//Konstruktor kopiuj¹cy
	pc_table_three = new CTable(*pc_table_one);

	cout << "\nObject pc_table_three: \n";
	cout << "Name: " << pc_table_three->sGetTableName() << "\n";
	cout << "Array length: " << pc_table_three->iGetTableLen() << "\n";

	//Metoda *pcClone()
	pc_table_four = pc_table_two->pcClone();

	cout << "\nObject pc_table_four: \n";
	cout << "Name: " << pc_table_four->sGetTableName() << "\n";
	cout << "Array length: " << pc_table_four->iGetTableLen() << "\n";

	//Statyczna alokacja obiektu, konstruktor bezparametrowy
	CTable pc_table_five;

	cout << "\nObject pc_table_five: \n";
	cout << "Name: " << pc_table_five.sGetTableName() << "\n";;
	cout << "Array length: " << pc_table_five.iGetTableLen() << "\n";;

	//Procedura v_mod_tab(CTable* pcTab, int iNewSize)
	v_mod_tab(&pc_table_five, 4);

	cout << "\nObject pc_table_five after calling v_mod_tab(CTable* pcTab, int iNewSize): \n";
	cout << "Name: " << pc_table_five.sGetTableName() << "\n";;
	cout << "Array length: " << pc_table_five.iGetTableLen() << "\n";;

	//Procedura v_mod_tab(CTable pcTab, int iNewSize)
	v_mod_tab(pc_table_five, 7);

	cout << "\nObject pc_table_five after calling v_mod_tab(CTable pcTab, int iNewSize): \n";
	cout << "Name: " << pc_table_five.sGetTableName() << "\n";;
	cout << "Array length: " << pc_table_five.iGetTableLen() << "\n";;

	//Alokacja tablicy obiektow
	CTable* pc_table_tab;
	pc_table_tab = new CTable[4];

	//Destruktor
	delete pc_table_one;
	delete pc_table_two;
	delete pc_table_three;
	delete pc_table_four;
	delete[] pc_table_tab;

	return 0;
}