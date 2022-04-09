#pragma once
#include "CTable.h"
#include <iostream>
#include <string>
using namespace std;

CTable::CTable() {

	s_name = DEFAULT_NAME;
	pi_table_len = DEFAULT_TABLE_LEN;
	pi_table = new int[pi_table_len];

	cout << "\n" << "bezp: '" << s_name << "'\n";
}

CTable::CTable(string sName, int iTableLen) {

	s_name = sName;

	if (iTableLen > 0 && iTableLen < 10000) {

		pi_table_len = iTableLen;
		pi_table = new int[pi_table_len];
	}
	else {

		pi_table_len = DEFAULT_TABLE_LEN;
		pi_table = new int[pi_table_len];

		cout << "\nInvalid array length, set to default!\n";
	}

	cout << "\n" << "parametr: '" << s_name << "'\n";
}

CTable::CTable(const CTable &pcOther) {

	s_name = pcOther.s_name + "_copy";
	pi_table_len = pcOther.pi_table_len;
	pi_table = new int[pi_table_len];

	for (int i = 0; i < pi_table_len; i++) {

		pi_table[i] = pcOther.pi_table[i];
	}

	cout << "\n" << "kopiuj: '" << s_name << "'\n";
}

CTable::~CTable() {

	delete[] pi_table;
	cout << "\n" << "usuwam: '" << s_name << "'\n";
}

void CTable::vSetName(string sName) {

	if (sName == "") {

		cout << "\n" << "Wrong name!" << "\n";
		return;
	}

	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {

	if ((iTableLen <= 0) || (iTableLen == pi_table_len) || (iTableLen > 10000)) {

		cout << "\n" << "Wrong table size!" << "\n";
		return false;
	}

	pi_table_len = iTableLen;
	delete[] pi_table;
	pi_table = new int[pi_table_len];

	return true;
}

string CTable::sGetTableName() {

	return s_name;
}

int CTable::iGetTableLen() {
	
	return pi_table_len;
}

CTable* CTable::pcClone() {

	CTable* pc_table_copy;
	pc_table_copy = new CTable(*this);

	return pc_table_copy;
}

void v_mod_tab(CTable* pcTab, int iNewSize) {

	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable pcTab, int iNewSize) {

	pcTab.bSetNewSize(iNewSize);
}