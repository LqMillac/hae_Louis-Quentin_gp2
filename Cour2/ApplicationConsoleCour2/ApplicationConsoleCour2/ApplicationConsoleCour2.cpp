// ApplicationConsoleCour2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"

void assert(bool b) {
	if(b)throw std::exception();
}

int main()
{
	//std::cout << "Hello World!\n"; 
	printf("%d\n", IntArray::TEST);
	auto nameTab0 = "tab0";
	auto nameTab1 = "tab1";

	//Variable dynamique
	//IntArray * montableau = new IntArray(16);
	//auto montableau = new IntArray(16);

	// Variable locale 
	{
		IntArray tab0 = IntArray(16, nameTab0);

	}
	{
		IntArray *tab1 = new IntArray(16, nameTab1);
		tab1->ensure(8) == false;
		tab1->ensure(32) == true;
		delete(tab1);
		tab1 = nullptr;
	}
	{
		IntArray t(16);
		t.set(0, 8);
		t.set(3, 66);
		/*for (int i = 0; i < t.getLength(); i++)
		{
			printf("t[%d]: %d\n", i, t[i]);
		}
		t[5] = 8;
		printf("t[%d]: %d\n", 5, t[5]);*/
	}
	{
		IntArray t(16);
		for (int i = 0; i < 8; i++)
		{
			t.set(i, i*i);
		}
			t.push_back(5);
			t.push_front(2);
			t.insert(4, 3);
	}
}


