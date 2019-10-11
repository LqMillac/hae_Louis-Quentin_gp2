// ApplicationConsoleCour2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "IntArray.hpp"

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
		IntArray tab0 = IntArray(16,nameTab0);
		
	}
	{
		IntArray *tab1 = new IntArray(16,nameTab1);
		
	}










}


