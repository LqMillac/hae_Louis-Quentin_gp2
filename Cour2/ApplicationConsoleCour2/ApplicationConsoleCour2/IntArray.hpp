#pragma once
#include <cstdio>
#include <cstdlib>
#include <string>

class IntArray {
public: 
	static int TEST;
	std::string name;
	int *data; // tableau dynamique qui va contenir nos données
	int maxSize=0; // 
	int curSize=0;

	IntArray(int size,const char * name = "")
	{
		int i = 0;
		this->name = name; // alloque automatiquement un char * et fait la copie 
		if(name) printf("construite! %s\n", name);

		// version C old school
		//data = (int *)malloc(size * sizeof(int));
		//memset (data,0 size *sizeof(int));

		//Version C New School 
		// data = (int * ) calloc (size,sizeof(int));
		// calloc mets des zero 
		if (size == 0) size++;

		// Version C++ plus safe 

		data = new int[size];
		for (int i = 0; i < size; i++)data[i] = 0;

		maxSize = size;
	}
	~IntArray()
	{
		printf("detruite! %s\n",name.c_str());
	}
	bool  ensure(int size);
	
	int get(int pos)
	{
		return data[pos];
	}
	void set(int pos, int elem)
	{
		ensure(pos+1);

		data[pos] = elem;
		curSize = pos +1; 
	}
	void set_unsafe(int pos, int elem)
	{
		data[pos] = elem; 
		curSize = pos+1;
	}
	int operator() (int pos)
	{
		ensure(pos+1);
		return data[pos];
	}
	int & operator[](int pos)
	{
		ensure(pos+1);
		return data[pos];
	}
	void push_back(int elem)
	{
		ensure(curSize+1);
		data[curSize] = elem;
		curSize++;

	}
	void push_front(int elem)
	{
		ensure(curSize+1);
		for (int i = curSize; i > 0; i--)
		{
			data[i] = data[i-1];
		}
		data[0] = elem;
		curSize++;
	}
	void insert(int pos, int elem)
	{
		ensure((pos>=curSize) ? (curSize+1) :(pos+1));
		for (int i = curSize; i > pos; i--)
		{
			data[i] = data[i - 1];
		}
		data[pos] = elem;
		if (pos >= pos + 1)
			curSize = pos + 1;
		else
		curSize++;
			

	}

};