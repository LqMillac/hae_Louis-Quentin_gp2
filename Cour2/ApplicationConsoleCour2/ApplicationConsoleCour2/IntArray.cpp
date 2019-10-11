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
	 ensure((pos >= curSize) ? (curSize + 1) : (pos + 1));

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
	 if (pos >= pos + 1)
		 curSize = pos + 1;
	 else
		 curSize++;


 }
