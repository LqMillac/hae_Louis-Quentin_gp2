#include "pch.h"
#include <string>

class Entrainement
{
public:
	int pv;
	std::string nom;
	int * tableau;
	int maxsize = 0;
	int cursize = 0;
	Entrainement(int size)
	{
		maxsize = size;
		tableau = new int[size];
		for (int i = 0; i < size; i++)
		{
			tableau[i] = 0;
			cursize++;
		}
		//cursize = size;
	}
	~Entrainement()
	{

	}

	void attribuervaleur(int max)
	{
		for (int i = 0; i < max; i++)
		{
			tableau[i] = 0;

		}
		cursize = max;
	}

	void ensure(int pos)
	{
		if (pos <= maxsize)
		{
			return;
		}
		if (pos > maxsize)
		{
			int* tempo = new int[pos];
			for (int i = 0; i < cursize; i++)
			{
				tempo[i] = tableau[i];
			}
			delete tableau;
			tableau = tempo;
			maxsize = pos + 1;
			for (int i = cursize; i < maxsize; i++)
			{
				tableau[i] = 0;
			}
		}

	}
	void set_unsafe(int pos, int elem)
	{
		tableau[pos] = elem;
	}
	void set_safe(int pos, int element)
	{

		ensure(pos + 1);
		tableau[pos] = element;
	}

	void push_back(int elem)
	{
		//if (cursize > maxsize - 1)
		//{
			ensure(maxsize + 1);
		//}
		tableau[cursize + 1] = elem;
		cursize++;
	}
	void push_front(int element)
	{
		//if (cursize > maxsize - 1)
		//{
			ensure(maxsize + 1);
		//}
		for (int i = 0; i <	 cursize; i++)
		{
			int temp = tableau[i + 1];
			tableau[i + 1] = tableau[i];
			tableau[i] = temp;
		}
		cursize++;
	}

};
