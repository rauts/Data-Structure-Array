#include "Array.h"

Array::Array(int size) {
	mSize = size;
	int *mPtr = new int[size];
}

Array::~Array() {
	delete[] mPtr;
}

