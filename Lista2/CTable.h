#ifndef CTABLE_H
#define CTABLE_H

#include <iostream>
#include <string>
using namespace std;

#define DEFAULT_NAME "default";
#define DEFAULT_TABLE_LEN 1;

class CTable {

public:
	CTable();	//Konstruktor bezparametrowy
	CTable(string sName, int iTableLen);	//Konstruktor z parametrami
	CTable(const CTable& pcOther);	//Konstruktor kopiujący
	//~CTable(); //Destruktor

	void vSetName(string sName);	//Metoda przypisująca polu s_name, wartość sName
	bool bSetNewSize(int iTableLen);	//Metoda mieniająca długość tablicy
	string sGetTableName();	//Getter, zwraca nazwe obiektu
	int iGetTableLen();	//Getter, zwraca dlugosc obiektu

	CTable* pcClone();	//Metoda zwracająca nowy obiekt klasy CTable, będący klonem obiektu dla którego pcClone() zostało wywołane

	void operator= (CTable& pcOther);
	CTable operator+ (const CTable& pcOther);

	void vSetValueAt(int  iOffset, int  iNewVal);
	void vPrint();

private:
	string s_name;
	int i_table_len;
	int* pi_table;
};

void v_mod_tab(CTable* pcTab, int iNewSize);	//Procedura odwolujaca sie poprzez wskaznik
void v_mod_tab(CTable pcTab, int iNewSize);		//Procedura operujaca na kopii

#endif