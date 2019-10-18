// cour3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"

void assert(bool b)
{
	if (!b) throw::std::exception();
}
int main()
{
	{
		IntArray Swap;
		Swap.fillWithRandom(16);
		int i = 0;
		Swap.InsertSort();

		for (int i = 0; i < Swap.getLength()-1; i++)
		{
			assert(Swap[i] < Swap[i + 1]);
		}
		int p = 0;

	}
	{
		IntArray Test;
		Test[0] = 66;
		Test[1] = 69;
		Test.swap(0, 1);
		assert(Test[0] == 69);
	}
	
}

