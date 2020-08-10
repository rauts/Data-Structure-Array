#include "Array.h"

Array::Array(int size) {
	if (size != 0) {
		mArraySize = size;
		mPtr = new int[mArraySize] {};
	}
}

Array::~Array() {
	delete[] mPtr;
}

int Array::Size() const {
	return mArraySize;
}

bool Array::IsEmpty() const {
	return (mArraySize == 0) && (mPtr == nullptr);
}

// TO DO
void Array::PrintArray() const {}

bool Array::IsmPtrNull() const {
	return mPtr == nullptr;
}