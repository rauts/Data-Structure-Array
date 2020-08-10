#include "Array.h"

Array::Array(int size) {
	mSize = size;
	int *mPtr = new int[size];
}

Array::~Array() {
	delete[] mPtr;
}

int Array::Size() const {
	return mSize;
}

bool Array::IsEmpty() const {
	return (mSize == 0) && (mPtr == nullptr);
}

// TO DO
void Array::PrintArray() const {}

