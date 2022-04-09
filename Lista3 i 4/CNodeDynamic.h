#ifndef CNODEDYNAMIC_H
#define CNODEDYNAMIC_H

#pragma once
#include <iostream>
#include <vector>
using namespace std;

template< typename T > class CNodeDynamic
{

public:
	CNodeDynamic();
	~CNodeDynamic(); //destruktor domyslny

	void vSetValue(T tNewVal);

	int iGetChildrenNumber();
	void vAddNewChild(CNodeDynamic<T>* pcNewChildNode);
	void vEraseFromParentVector(CNodeDynamic<T>* pcEraseChildNode);
	void vAddNewChild();
	CNodeDynamic<T>* pcFindRoot();
	CNodeDynamic<T>* pcGetChild(int iChildOffset);
	CNodeDynamic<T>* pcGetParent();
	void vPrint();
	void vPrintAllBelow();

private:
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T t_val;
};

template <typename T>
CNodeDynamic<T>::CNodeDynamic() {

	pc_parent_node = NULL;
};

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {

	for (int i = 0; i < v_children.size(); i++) {

		delete v_children.at(i);
	}

}

template <typename T>
void CNodeDynamic<T>::vSetValue(T tNewVal) {

	t_val = tNewVal;
}

template <typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {

	return(v_children.size());
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* pcNewChildNode) {

	pcNewChildNode->pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}

template <typename T>
void CNodeDynamic<T>::vEraseFromParentVector(CNodeDynamic<T>* pcEraseChildNode) {

	for (int i = 0; i < v_children.size(); i++) {

		if (pcEraseChildNode == v_children.at(i)) {

			v_children.erase(v_children.begin() + i);
		}
	}
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild() {

	CNodeDynamic<T>* child = new CNodeDynamic<T>;
	child->pc_parent_node = this;
	v_children.push_back(child);
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcFindRoot() {

	if (pc_parent_node != NULL) {
		pc_parent_node->pcFindRoot();
	}
	else {

		return this;
	}
}
template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {


	if (iChildOffset < v_children.size() && iChildOffset >= 0) {

		return v_children.at(iChildOffset);
	}
	else {

		return NULL;
	}
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetParent() {

	return pc_parent_node;
}

template <typename T>
void CNodeDynamic<T>::vPrint() {

	cout << " " << t_val;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {

	vPrint();

	for (int i = 0; i < v_children.size(); i++) {

		v_children.at(i)->vPrintAllBelow();
	}
}
#endif
