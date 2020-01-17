// Entrainement du Cour 2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "Class.hpp"

int main()
{
	Entrainement perso = Entrainement(5);
	
	//perso.attribuervaleur(5);
	//perso.set_safe(2,3);
	//perso.set_unsafe(8, 3);
	perso.push_back(-10);
	perso.push_back(10);
	perso.push_front(5);
	int test = 0;
}

