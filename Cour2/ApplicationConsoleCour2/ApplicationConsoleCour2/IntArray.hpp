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
		//if(name) printf("construite! %s\n", name);

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
		//printf("detruite! %s\n",name.c_str());
	}
	bool  ensure(int size);
	
	int getLength()
	{
		return curSize;
	}
	int get(int pos)
	{
		return data[pos];
	}
	void set(int pos, int elem)
	{
		ensure(pos+1);
		data[pos] = elem;
		if (pos >= curSize) curSize = pos + 1;
	}
	void set_unsafe(int pos, int elem)
	{
		data[pos] = elem; 
		curSize = pos+1;
	}
	int & operator() (int pos)
	{
		ensure(pos+1);
		if (pos >= curSize) curSize = pos + 1;
		return data[pos];
	}
	int & operator[](int pos)
	{
		ensure(pos+1);
		if (pos >= curSize) curSize = pos + 1;
		return data[pos];
	}
	void push_back(int elem);
	void push_front(int elem);
	void insert(int pos, int elem);

	int searchposition(int element )
	{
		for (int i = 0; i < getLength(); i++)
		{
			//printf("j'examine i:%d", i);
			if (element <=  data[i])
				return i;
			
		}
		return getLength();
		
	}
	bool remove(int valeur)
	{
		int idx = -1;
		for (int i = 0; i < getLength(); i++)
		{
			if (data[i] == valeur)
			{
				idx = i;
				break;
			}
		}
		if (idx == -1)return false; 
		for (int i = idx; i < getLength() - 1; i++)
		{
			data[i] = data[i + 1];
			
		}
		data[curSize - 1] = 0;
		curSize--;

		
	}
	void removeAll()
	{
		
		for (int i = 0; i < getLength(); i++)
		{
			data[i] = 0;
		}
		
	}

};
	