#pragma once
#include "CTable.h"
#include <iostream>
#include <string>
using namespace std;

CTable::CTable() {

	s_name = DEFAULT_NAME;
	i_table_len = DEFAULT_TABLE_LEN;
	pi_table = new int[i_table_len];

	cout << "\n" << "bezp: '" << s_name << "'\n";
}

CTable::CTable(string sName, int iTableLen) {

	s_name = sName;

	if (iTableLen > 0) {

		i_table_len = iTableLen;
		pi_table = new int[i_table_len];	
	}
	else {

		i_table_len = DEFAULT_TABLE_LEN;
		pi_table = new int[i_table_len];
		cout << "\nInvalid array length! Set to default!\n";
	}

	cout << "\n" << "parametr: '" << s_name << "'\n";
}

CTable::CTable(const CTable& pcOther) {

	s_name = pcOther.s_name + "_copy";
	i_table_len = pcOther.i_table_len;
	pi_table = new int[i_table_len];

	for (int i = 0; i < i_table_len; i++) {

		pi_table[i] = pcOther.pi_table[i];
	}

	cout << "\n" << "kopiuj: '" << s_name << "'\n";
}

/*CTable::~CTable() {

	delete[] pi_table;
	cout << "\n" << "usuwam: '" << s_name << "'\n";
}*/

void CTable::vSetName(string sName) {

	if (sName == "") {

		cout << "\n" << "Wrong name!" << "\n";
		return;
	}

	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {

	if ((iTableLen <= 0) || (iTableLen == i_table_len)) {

		cout << "\n" << "Wrong table size!" << "\n";
		return false;
	}

	i_table_len = iTableLen;
	delete[] pi_table;
	pi_table = new int[i_table_len];

	return true;
}

string CTable::sGetTableName() {

	return s_name;
}

int CTable::iGetTableLen() {

	return i_table_len;
}

CTable* CTable::pcClone() {

	CTable* pc_table_copy;
	pc_table_copy = new CTable(*this);

	return pc_table_copy;
}

void CTable::operator=(CTable& pcOther)
{

	pi_table = pcOther.pi_table;
	i_table_len = pcOther.i_table_len;
}

/*void CTable::operator=(CTable& pcOther)
{

	if (this == &pcOther) {

		return;
	}

	delete[] pi_table;

	i_table_len = pcOther.i_table_len;
	s_name = pcOther.s_name;
	pi_table = new int[i_table_len];

	for (int i = 0; i < i_table_len; i++) {

		pi_table[i] = pcOther.pi_table[i];
	}
}*/

CTable CTable::operator+(const CTable& pcOther) {

	CTable result_c_table ("concatenated_tables", i_table_len + pcOther.i_table_len);
	
	for (int i = 0; i < i_table_len; i++) {

		result_c_table.pi_table[i] = pi_table[i];
	}
	for (int j = i_table_len; j < result_c_table.i_table_len ; j++) {

		result_c_table.pi_table[j] = pcOther.pi_table[j - i_table_len];
	}

	return result_c_table;
}

void CTable::vSetValueAt(int  iOffset, int  iNewVal) {

	if (iOffset >= i_table_len || iOffset < 0) {

		return;
	}

	pi_table[iOffset] = iNewVal;
}

void CTable::vPrint() {

	cout << "Name: " << s_name << "\n";;
	cout << "Array length: " << i_table_len << "\n";;

	for (int i = 0; i < i_table_len; i++) {

		cout << s_name << "[" << i << "]=" << pi_table[i] << "\n";
	}
}

void v_mod_tab(CTable* pcTab, int iNewSize) {

	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable pcTab, int iNewSize) {

	pcTab.bSetNewSize(iNewSize);
}