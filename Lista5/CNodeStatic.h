#ifndef CNODESTATIC_H
#define CNODESTATIC_H

#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CNodeStatic {

public:
	CNodeStatic();
	~CNodeStatic(); //destruktor domyslny

	void vSetValue(int iNewVal);

	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeStatic pcNewChildNode);
	void vEraseFromParentVector(CNodeStatic *pcEraseChildNode);
	CNodeStatic* pcFindRoot();
	CNodeStatic* pcGetChild(int iChildOffset);
	CNodeStatic* pcGetParent();
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp(); //potrzebny jest pc_parent_node

private:
	vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;
};

#endif
