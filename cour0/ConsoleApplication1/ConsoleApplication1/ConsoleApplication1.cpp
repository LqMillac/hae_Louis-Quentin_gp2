// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
//#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>
int appel(int s) {
	s++;

	return 0;
}
Vec3 incrX(Vec3 _in) {
	_in.x++;
	return _in;
};
/*Vec3 stackOverFlow(Vec3 _in) {
	Vec3 temp = _in;
	temp.y++; 
	return stackOverFlow(temp);
}*/
int main()

{
	//int x = 66;
	//appel(x);
	//printf("xval:%d\n", x);
	//// 68 ?
	//Vec3 toto = { 1,2,3 };// new vec3()
	//toto =incrX(toto);
	//printf("xval:%f\n", toto.x);

	int *v = (int*)malloc(4);

	/*Vec3 bob = { 1,2,3 };
	bob =stackOverFlow(bob);
	printf("val x : %f\n", bob.x);*/
	
	Vec3 vecTab[3];
	vecTab[0] = { 66,66,66};
	vecTab[1] = { 4,5,6 };
	vecTab[2] = { 7,8,9 };
	printf("v0x %f\n", vecTab[0].x);


	Vec3 *t0 = 0;
	Vec3 *t1 = nullptr;
	Vec3 *t2 = &vecTab[1];
	
	t2++;

	(*t2).y = 777;
	t2->y = 888;
	Vec3* iter = &vecTab[0];
	int i = 0;
	for (i = 0; i < 3; ++i) {
	
		printf("val vec x: %d\n", iter->x);
		iter++;
	}

	Vec3 *t3 = t2 + 1;
	t2++;

	const char label2[6] = { 's','a','p','i','n',0 };

	const char * ptr = &label2[0];
	ptr++;
	printf("%c\n",*ptr);

	

	auto start = std::chrono::system_clock::now();

	int * bigBlock = (int*) malloc(1024*1024 * 1024 * 1024);

	for (int k = 0; k < 64 * 1024 * 1024; ++k)
	{
		bigBlock[k] = 0xdeadbeef;
	}


	printf("beef ? : %x\n", bigBlock[1024 * 1024]);

	auto end = std::chrono::system_clock::now();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	printf("time ? :%d\n", millis);

	int _i = 0;

	








   // std::cout << "Hello World!\n"; 
	/*
	int goo = 0;
	const char * label = "sapin";
	const char label2[6] = { 's','a','p','i','n',0 };
	float v = 0.5f;
	double ff = 0.5;
	//printf("Hello world this is a test : %d label :%s %f\n",goo,label,66.66f);

	//printf("Hello world this is a test : a fraction %f\n", ((float)1.0f/3.0f));
	//printf("Hello world :l2 %s\n", label2);
	//const char labelbug[5] = { 's','a','p','i','n' };
	*/

	
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
