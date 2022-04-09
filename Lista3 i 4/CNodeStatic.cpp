#pragma once
#include "CNodeStatic.h"
#include <iostream>
using namespace std;

CNodeStatic::CNodeStatic() {

	i_val = 0; pc_parent_node = NULL;
};

CNodeStatic::~CNodeStatic() {

	//destruktor domyslny
}

void CNodeStatic::vSetValue(int iNewVal) {

	i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {

	return(v_children.size());
}

void CNodeStatic::vAddNewChild() {

	CNodeStatic child;
	child.pc_parent_node = this;
	v_children.push_back(child);
}

void CNodeStatic::vAddNewChild(CNodeStatic pcNewChildNode) {

	pcNewChildNode.pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}

void CNodeStatic::vEraseFromParentVector(CNodeStatic *pcEraseChildNode) {
	
	for (int i = 0; i < v_children.size(); i++) {
		
		if (pcEraseChildNode == &(v_children.at(i))) {
			v_children.erase(v_children.begin() + i);
			break;
		}
	}
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {

	if (iChildOffset < v_children.size() && iChildOffset >= 0) {

		return &(v_children.at(iChildOffset));
	}
	else {

		return NULL;
	}
}

CNodeStatic* CNodeStatic::pcGetParent() {

	return pc_parent_node;
}

void CNodeStatic::vPrint() {

	cout << " " << i_val;
}

void CNodeStatic::vPrintAllBelow() {

	vPrint();

	for (int i = 0; i < v_children.size(); i++) {

		v_children.at(i).vPrintAllBelow();
	}
}

void CNodeStatic::vPrintUp() {

	vPrint();

	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}
}

CNodeStatic* CNodeStatic::pcFindRoot() {

	if (pc_parent_node != NULL) {
		pc_parent_node->pcFindRoot();
	}
	else {

		return this;
	}
}