

#include "pch.h"
#include <iostream>


static void TestRec();

int Max(int a, int b)
{
	return (a < b) ? b : a;
}
int Min(int a, int b)
{
	return (a > b) ? a : b;
}

int strcmp(char * meule, char * aiguille)
{
	int lenMeule = strlen(meule);
	int lenAiguille = strlen(aiguille);

	int maxLen = Max(lenMeule, lenAiguille);
	int minLen = Min(lenMeule, lenAiguille);

	for (int i = 0; i < minLen; i++)
	{
		if (meule[i] < aiguille[i])
		{
			return -1;
		}
		else if (meule[i] > aiguille[i])
		{
			return 1;
		}
		// if equal continue 
	}
	//une des deux chaines est plus courte que l'autre 

	if (minLen == maxLen)
	{
		return 0;
	}

	if (maxLen == lenMeule)
	{
		return 1;
	}
	return -1;
}

char * StrStr(char * meuleDeFoin, char * aiguille)
{
	int lenMeule = strlen(meuleDeFoin);
	int lenAiguille = strlen(aiguille);

	for (int i = 0; i<lenMeule; i++)
	{
		bool(found) = true;
		for (int j = 0; j < lenAiguille; j++)
		{
			if (meuleDeFoin[j] != aiguille[j])
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return meuleDeFoin;
			
		}
		meuleDeFoin++;

	}
	return nullptr;
}


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

int add_0(int a, int b)
{
	int i = 0;
	for (i = 0; i < a + b; i++);
	return i;
}
int add_1(int a, int b)
{
	int val = a;
	for (int i = 0; i < b; i++);
	val++;
	return val;
}
int add_2(int a, int b)
{
	// add_2 (7 8)
	// add_2 (6 9)
	// add_2 (5 10)
	// add_2 (0 15)
	// a+0 => a
	if (a == 0)
		return b;
	else 
	return add_2(a - 1, b + 1);
}
int add_3(int a, int b)
{
	
	if (a == 0)		    return b;
	else if (b == 0)	return a;
	else
	{

		int inter = 1 + add_3(a - 1, b);
		printf("a:%d,b:%d, = %d\n", a,b,inter);
		return inter;

	}
}

int sub(int a, int b)
{
	
	printf("a:%d,b:%d\n", a, b);
	if (b == 0) return a;
	else if (b > 0)
		return sub(a, b - 1) - 1;
	else 
		return sub(a, b +1) +1;
}

int mult(int a, int b)

{
	
	if (b == 0) return 0;
	if (a == 0) return 0;
	if (b < 0) return -mult(a, -b);
	else
		return  a + mult(a,b-1);


}

int Division(int a, int b)
{
	if (a == 0)               return 0;
	if (a < 0 && b < 0)       return -Division(a, b);
	if (a < 0)                return -Division(-a, b);
	if (b < 0)                return -Division(a, -b);
	if (a < b)                return 0;
	else
		return 1 + Division(a - b, b);
}
int quotien(int a, int b)
{
	if (a == 0) return 0;
	if (b == 0) return a;
	if (a < 0) return 0;
	if (b < 0) return a;

	else
		return (a - mult(b, Division(a, b)));


		// mod (a,b) = a-mult (b,div(a,b))
}
int Strlen(const char * src )
{
	if (* src==0) return 0;
	else
		return 1 + Strlen( src+1);
	

}
void Strcopy(char *dest , const char *src)
{
	*dest = *src;
	if (*src == 0)
		return;
	else
		 Strcopy(dest + 1, src + 1);
}

void ZeroMemory(char *dest, int size)
{
	if (size == 0) return; 
	*dest = 0;
	ZeroMemory(dest + 1, size -1);
}

void MempyRec(char *dest, const char *src, int size)
{
	if (size-1 < 0)
	{
		*dest = 0;
		return;
	}
	*dest = *src; 
	MempyRec(dest + 1, src + 1, size - 1);
}

int StrcmRec(char *str0, char *str1)
{
	if (*str0 == 0 && *str1 == 0) return 0; 
	if (*str0 == 0) return 1;
	if (*str1 == 0) return -1;
	if (*str0 < *str1) return -1;
	if (*str0 > *str1) return 1;
	return StrcmRec(str0+1 ,str1+1);

}
void StrcatRec(char *str0, char *str1)
{
	if (*str1 == 0) return; 
	if (*str0 == 0) return StrcatRec(str0, str1);
}

void TestRec()
{
	/*int foo = add_2(2, 2);
	int foo2 = add_3(5, 4);*/
	
	//int foo3 = sub(8, 2);
	//int foo4 = mult(2, 2);
	//int foo5 = mult(2, -5);
	//int foo6 = Division(10, 2);
	//printf("%d\n", Division(10, 2));
	//int foo7 = quotien(16, 3);
	int i = 0;
	char dest[30];
	
	int len = Strlen("sapin");
	 // Strcopy(dest,"chene");
	//printf("%d\n", len);
	//printf("%s\n", dest);
	//int sizeBuf = 32;
	//char *buffer = (char*)malloc(sizeBuf + 1);
	//buffer[32] = 'X';
	//ZeroMemory(buffer, sizeBuf);
	//printf("%c", buffer[32]);
	//system("pause");
	MempyRec(dest, "lapin",2);
	printf("%s\n", dest);

	{
		 char lapin[32] = "a";
		 char lapine[32] = "a";
		 int resultat = StrcmRec(lapin, lapine);
		 printf("%d\n", resultat);
		
	}
	{
		char lapin[32] = "b";
		char lapine[32] = "a";
		int resultat = StrcmRec(lapin, lapine);
		printf("%d\n", resultat);

	}
	{
		char lapin[32] = "a";
		char lapine[32] = "b";
		int resultat = StrcmRec(lapin, lapine);
		printf("%d\n", resultat);

	}

	
	
	
	
	
	
}

int main()
{
    /*std::cout << "Hello World!\n"; 

	char licorne[32] = "licorne";
	char vomi[32] = "vomit";
	//Memcpy(licorne, vomi,strlen(licorne)+1);
	Memcpy2(licorne, vomi, strlen(licorne) + 1);

	printf("licorne %s\n", licorne);


	char chateau[32]= "chateau";
	char soldat = 'e';
	int posSoldat = StrChr4(chateau, soldat);
	printf("le chateau est en position %d\n", posSoldat);


	char text[1024] = "Lorem ipsum dolor sit amet";
	char token [1024]= "dolor";
	char*tokenIText = StrStr(text,token);
	int pos = (int)(tokenIText - text);
	printf("le token est en position %d\n", pos);
	int a = 0;
	char text0[] = "licorne";
	char text1[] = "licorn";
	printf("%d\n",strcmp(text0, text1));
	printf("%d\n", strcmp(text1, text0));*/

	TestRec();
	
}

