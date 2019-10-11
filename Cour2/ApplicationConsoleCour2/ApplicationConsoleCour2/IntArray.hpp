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

	IntArray(int size,const char * name = nullptr)
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

		// Version C++ plus safe 

		data = new int[size];
		for (int i = 0; i < size; i++)data[i] = 0;

		maxSize == size;
	}
	~IntArray()
	{
		printf("detruite! %s\n",name.c_str());
	}
};