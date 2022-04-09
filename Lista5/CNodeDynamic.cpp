#pragma once
#include "CNodeDynamic.h"
#include <iostream>
using namespace std;

CNodeDynamic::CNodeDynamic() {

	i_val = 0; pc_parent_node = NULL;
};

CNodeDynamic::~CNodeDynamic() {

	for (int i = 0; i < v_children.size(); i++) {

		delete v_children.at(i);
	}

	v_children.clear();
}

void CNodeDynamic::vSetValue(int iNewVal) {

	i_val = iNewVal;
}


int CNodeDynamic::iGetChildrenNumber() {

	return(v_children.size());
}

void CNodeDynamic::vAddNewChild(CNodeDynamic* pcNewChildNode) {

	pcNewChildNode->pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}

void CNodeDynamic::vEraseFromParentVector(CNodeDynamic* pcEraseChildNode) {

	for (int i = 0; i < v_children.size(); i++) {

		if (pcEraseChildNode == v_children.at(i)) {

			v_children.erase(v_children.begin() + i);
		}
	}
}

void CNodeDynamic::vAddNewChild() {

	CNodeDynamic* child = new CNodeDynamic;
	child->pc_parent_node = this;
	v_children.push_back(child);
}

CNodeDynamic* CNodeDynamic::pcFindRoot() {

	if (pc_parent_node != NULL) {
		pc_parent_node->pcFindRoot();
	}
	else {

		return this;
	}
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {


	if (iChildOffset < v_children.size() && iChildOffset >= 0) {

		return v_children.at(iChildOffset);
	}
	else {

		return NULL;
	}
}

CNodeDynamic* CNodeDynamic::pcGetParent() {

	return pc_parent_node;
}

void CNodeDynamic::vPrint() {

	cout << " " << i_val;
}

void CNodeDynamic::vPrintAllBelow() {

	vPrint();

	for (int i = 0; i < v_children.size(); i++) {

		v_children.at(i)->vPrintAllBelow();
	}

}