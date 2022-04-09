#pragma once
#include "CTreeStatic.h"
#include "CNodeStatic.h"
#include <iostream>
using namespace std;

CTreeStatic::CTreeStatic() {

}

CTreeStatic::~CTreeStatic() {

}

CNodeStatic* CTreeStatic::pcGetRoot() {

	return(&c_root);
}

void CTreeStatic::vPrintTree() {

	c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode) {

	if (pcParentNode == NULL || pcNewChildNode == NULL || pcParentNode->pcFindRoot() == pcNewChildNode->pcFindRoot()) {

		return false;
	}
	else if (pcNewChildNode->pcGetParent() == NULL) {

		pcParentNode->vAddNewChild(*pcNewChildNode);

		return true;
	}
	else {
		pcParentNode->vAddNewChild(*pcNewChildNode);
		pcNewChildNode->pcGetParent()->vEraseFromParentVector(pcNewChildNode);

		return true;
	}
}