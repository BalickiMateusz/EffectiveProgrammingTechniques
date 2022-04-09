#ifndef CTREESTATIC_H
#define CTREESTATIC_H

#pragma once
#include <iostream>
#include <vector>
#include "CNodeStatic.h"
using namespace std;

class  CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot();
	void  vPrintTree();
	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
private:
	CNodeStatic  c_root;
};

#endif