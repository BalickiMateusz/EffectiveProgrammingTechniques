#include "CTreeStatic.h"
#include "CTreeDynamic.h"
#include <iostream>
using namespace std;

void  v_node_static_test()
{	

	CNodeStatic  c_root;

	c_root.vAddNewChild();
	c_root.vAddNewChild();

	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);

	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();

	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();

	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	printf("Print below\n");
	c_root.vPrintAllBelow();
	printf("\n");
	printf("Print up\n");
	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

void v_tree_static_test() {

	CTreeStatic c_tree1;

	c_tree1.pcGetRoot()->vAddNewChild();
	c_tree1.pcGetRoot()->vAddNewChild();
	c_tree1.pcGetRoot()->vAddNewChild();

	c_tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree1.pcGetRoot()->pcGetChild(2)->vSetValue(3);

	c_tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();

	c_tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	c_tree1.pcGetRoot()->vPrintAllBelow();
	printf("\n");

	CTreeStatic c_tree2;

	c_tree2.pcGetRoot()->vSetValue(50);

	c_tree2.pcGetRoot()->vAddNewChild();
	c_tree2.pcGetRoot()->vAddNewChild();

	c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

	c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	c_tree2.pcGetRoot()->vPrintAllBelow();
	printf("\n");

	c_tree1.bMoveSubtree(c_tree1.pcGetRoot()->pcGetChild(2), c_tree2.pcGetRoot()->pcGetChild(0));

	c_tree1.pcGetRoot()->vPrintAllBelow();
	printf("\n");
	c_tree2.pcGetRoot()->vPrintAllBelow();
	printf("\n");
}

void v_tree_dynamic_test() {

	CTreeDynamic<int> *c_tree1 = new CTreeDynamic<int>();

	c_tree1->pcGetRoot()->vAddNewChild();
	c_tree1->pcGetRoot()->vAddNewChild();
	c_tree1->pcGetRoot()->vAddNewChild();

	c_tree1->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree1->pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree1->pcGetRoot()->pcGetChild(2)->vSetValue(3);

	c_tree1->pcGetRoot()->pcGetChild(2)->vAddNewChild();

	c_tree1->pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	c_tree1->pcGetRoot()->vPrintAllBelow();
	printf("\n");

	CTreeDynamic<int>* c_tree2 = new CTreeDynamic<int>();

	c_tree2->pcGetRoot()->vSetValue(50);

	c_tree2->pcGetRoot()->vAddNewChild();
	c_tree2->pcGetRoot()->vAddNewChild();

	c_tree2->pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_tree2->pcGetRoot()->pcGetChild(1)->vSetValue(55);

	c_tree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

	c_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	c_tree2->pcGetRoot()->vPrintAllBelow();
	printf("\n");

	c_tree1->bMoveSubtree(c_tree1->pcGetRoot()->pcGetChild(2), c_tree2->pcGetRoot()->pcGetChild(0));

	c_tree1->pcGetRoot()->vPrintAllBelow();
	printf("\n");
	c_tree2->pcGetRoot()->vPrintAllBelow();
	printf("\n");

	delete c_tree1;
	delete c_tree2;
}

int main() {

	int* cos;
	int x = 5;
	cos = &x;
	cout << *cos;

	//cout << x;
	//v_node_static_test();
	//v_tree_static_test();
	//v_tree_dynamic_test();
	return 0;
}