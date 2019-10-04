

#include "pch.h"
#include <iostream>

int StrChr(char*grange, char chat)
{
	for (int i = 0; grange[i] !=0 ; i++)
	{
		if (grange[i] == chat)
		{
			return i;
		}
 
	}
	return -1;

}
int StrChr2(char*grange, char chat)
{
	int i = 0;
	
	while (grange[i]!=0)
	{
	
		if (grange[i] == chat)
		{

			return i;
		}
		i++;
	}
	return-1;
}
int StrChr3(char*grange, char chat)
{
	int length = strlen(grange);
	for (int i = 0; i < length; i++)
	{
		return i;
	}
	return-1;
}
int StrChr4(char*grange, char chat)
{
	char *oldGrange = grange;

	while (*grange)
	{

		if (*grange == chat)
		{

			return (int)(grange - oldGrange);
		}
		grange++;;
	}
	return-1;
}


//void Memcpy(char * dest, char * src, int size) 
//{
//	for (int i = 0; i< size; i++)
//	{
//		dest[i] = src[i];
//	}
//
//
//}
void Memcpy2(char * dest, char * src, int size)
{
	while (size <= -1)
	{
		dest[size] = src[size];
		size--;
	}

	// AUTRE SOLUTION 
	// while (size--)
	//tant que (valeur sur la pile ) 
	// laisser la valeur de size sur la pile 
	// faire le tant que 
	// décremente la valeur de size 
}

int main()
{
    std::cout << "Hello World!\n"; 

	char licorne[32] = "licorne";
	char vomi[32] = "vomit";
	//Memcpy(licorne, vomi,strlen(licorne)+1);
	Memcpy2(licorne, vomi, strlen(licorne) + 1);

	printf("licorne %s\n", licorne);


	char chateau[32]= "chateau";
	char soldat = 'e';
	int posSoldat = StrChr4(chateau, soldat);
	printf("le chateau est en position %d\n", posSoldat);
}
