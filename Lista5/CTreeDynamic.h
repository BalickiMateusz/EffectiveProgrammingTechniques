#ifndef CTREEDYNAMIC_H
#define CTREEDYNAMIC_H

#pragma once
#include <iostream>
#include <vector>
#include "CNodeDynamic.h"
using namespace std;

template< typename T > class  CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T>* pcGetRoot();
	void  vPrintTree();
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
private:
	CNodeDynamic<T> *pc_root;
};

template <typename T>
CTreeDynamic<T>::CTreeDynamic() {

	pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {

	delete pc_root;
}

template <typename T>
CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot() {

	return(pc_root);
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {

	pc_root->vPrintAllBelow();
	cout << endl;
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode) {

	if (pcParentNode == NULL || pcNewChildNode == NULL || pcParentNode->pcFindRoot() == pcNewChildNode->pcFindRoot()) {

		return false;
	}
	else if (pcNewChildNode->pcGetParent() == NULL) {

		pcParentNode->vAddNewChild(pcNewChildNode);

		return true;
	}
	else {

		CNodeDynamic<T>* pcNewChildParentNode = pcNewChildNode->pcGetParent();
		pcParentNode->vAddNewChild(pcNewChildNode);
		pcNewChildParentNode->vEraseFromParentVector(pcNewChildNode);

		return true;
	}
}
#endif