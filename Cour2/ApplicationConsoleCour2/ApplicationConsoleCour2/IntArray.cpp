#include "pch.h"
#include "IntArray.hpp"

int IntArray::TEST = 66;

 bool IntArray::ensure(int size)
{
	if (size < maxSize) return false;
	int *newdata = new int[size];
	for (int i = 0; i < size; ++i) newdata[i] = 0;

	for (int i = 0; i < curSize; i++)
		newdata[i]=data[i];

	delete(data);
	data = newdata;

	printf("on passe ");

	return true;


}
