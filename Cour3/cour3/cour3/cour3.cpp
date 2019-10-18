#include "pch.h"
#include <iostream>
#include "IntArray.hpp"
#include "Util.hpp"
#include "List.hpp"
#include "Tree.hpp"

void assert(bool b) {
	if (!b) throw std::exception();
}

void TestIntTree() {
	IntTree * tree = new IntTree();
	Node<int> * leaf = new IntNode(8);
	leaf->insert(4);
	//assert(leaf->left->elem == 4);

	leaf->insert(9);
	//assert(leaf->right->elem == 9);

	leaf->insert(16);
	leaf->insert(3);
	leaf->insert(5);
	assert(leaf->getLength() == 6);


	assert(leaf->Contains(16) == true);
	leaf->remove(16);
	assert(leaf->Contains(16) == false);
	assert(leaf->Contains(4) == true);
	leaf->remove(4);
	assert(leaf->Contains(4) == false);
	leaf->insert(0);
	assert(leaf->Contains(0) == true);
	leaf->remove(0);
	assert(leaf->Contains(0) == false);

	int k = 0;
	leaf->dfsPrint();
	leaf->dfsPrintReverse();
}
void testIntList()
{
	/*IntList *LaListe = new IntList(8);
	int toto = 0;
	LaListe->Append(65);
	assert(LaListe->Length() == 2);

	LaListe = LaListe->AddFirst(33);
	assert(LaListe->Length() == 3);
	assert(LaListe -> elem == 33);

	LaListe = LaListe->Remove(12);
	assert(LaListe->Length() == 3);
	LaListe = LaListe->Remove(33);
	assert(LaListe->Length() == 2);
	

	bool LaReponse = LaListe->Contains(60);
	assert(LaReponse == false);

	bool LaReponse2 = LaListe->Contains(65);
	assert(LaReponse2 == true);

	int k = 0;*/
}
int main()
{
	testIntList();
	TestIntTree();
	
	

	/*const int len = 4;
	int sizes[len] = { 4, 8, 16, 32 };
	double prev = 0.000000000001;
	for (int k = 0; k < len; k++)
	{
		double t0 = TimeUtils::getTimestamp();
		IntArray toto(16);
		toto.fillWithRandom(256 * sizes[k]);
		toto.insertSort();
		for (int i = 0; i < toto.getLength() - 1; i++)
			assert(toto[i] <= toto[i + 1]);
		double t1 = TimeUtils::getTimestamp();
		printf("temps de calcul: %f s for %d\n", (t1 - t0), toto.getLength());
		int j = 0;
		auto cur = t1 - t0;
		printf("rapport:%f\n", cur / prev);
		prev = t1 - t0;
	}


	{
		IntArray test;
		test[0] = 66;
		test[1] = 69;
		test.swap(0, 1);
		assert(test[0] == 69);
	}

	int k = 0;

	{
		IntArray test(1000);
		for (int i = 0; i < 255; i++) {
			test[i] = i * 10;
		}
		assert(test.binarySearch(10) >= 0);
		assert(test.binarySearch(10) < test.getLength());
	}

	{
		IntArray test(1000);
		assert(test.binarySearch(10) == 0);
	}
	{
		IntArray test(10);
		int pos = 0;
		test[pos++] = 5;
		test[pos++] = 10;
		test[pos++] = 15;
		test[pos++] = 50;

		assert(test.binarySearch(4) == 0);
		assert(test.binarySearch(5) == 0);
		assert(test.binarySearch(6) == 1);
		assert(test.binarySearch(50) == 3);
		assert(test.binarySearch(60) == 4);
	}

	{
		IntArray test(10);
		int pos = 0;
		test[pos++] = 1;
		test[pos++] = 3;
		test[pos++] = 8;
		test[pos++] = 10;
		test[pos++] = 15;
		test[pos++] = 17;
		test[pos++] = 20;

		for (int i = 0; i < 10; ++i) {
			printf("i:%d  b:%d lin:%d \n", i, test.binarySearch(i), test.searchPosition(i));
			assert(test.binarySearch(i) == test.searchPosition(i));
		}
		{
			int bpos = test.binarySearch(2);
			int here = 0;
		}
		{
			printf("----------------------\n");
			int bpos = test.binarySearch(12);
			int here = 0;
		}
	}

	int l = 0;*/


}
