#include "pch.h"
#include "IntArray.hpp"

int IntArray::TEST = 66;

bool IntArray::ensure(int size) {
	if (size < maxSize) return false;

	int* newdata = new int[size];

	for (int i = 0; i < size; ++i) newdata[i] = 0;
	for (int i = 0; i < curSize; i++)
		newdata[i] = data[i];

	delete(data);
	data = newdata;

	maxSize = size;
	//printf("on passe");
	return true;
}

  void IntArray::push_back(int elem)
 {
	 ensure(curSize + 1);
	 data[curSize] = elem;
	 curSize++;

 }

 void IntArray::push_front(int elem)
 {
	 ensure(curSize + 1);
	 for (int i = curSize; i > 0; i--)
	 {
		 data[i] = data[i - 1];
	 }
	 data[0] = elem;
	 curSize++;
 }

void IntArray::insert(int pos, int elem)
 {
	 ensure((pos >= curSize) ? (pos + 1) : (curSize + 1));

	 /* if (( pos >=curSize))
	 {
	 ensure(pos+1);
	 else 
	 ensure (curSize +1);
	 }
	 */
	 for (int i = curSize; i > pos; i--)
	 {
		 data[i] = data[i - 1];
	 }
	 data[pos] = elem;
	 if (pos >= curSize)
		 curSize = pos + 1;
	 else
		 curSize++;


 }

/*void IntArray::sort()
{
	IntArray nuData(5, "nudata");
	for (int i = 0; i < getLength()-1; i++)
	{
		int val = get(i);
		printf("val : %d\n", val);
		int pos = nuData.searchposition(val);
		printf("future pos : %d\n", pos);
		nuData.insert(nuData.searchposition(val), val);
		printf("[");
		for (int j = 0; j < nuData.getLength()-1; j++)
		{
			printf("%d ", nuData[j]);
		}
		printf("]\n");

	}
	for (int i = 0; i < getLength(); i++)
	{
		set(i, nuData.get(i));
	}
	int i = 0;
}*/
