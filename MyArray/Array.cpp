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

// reading 
int Array::operator[](const int index) const {	
	return mPtr[index];
}

// writing
int& Array::operator[](const int index) {
	return mPtr[index];
}

Array::Array(Array const& arr)
{
	// allocate memory
	if (!arr.IsEmpty()) {
		mArraySize = arr.mArraySize;
		mPtr = nullptr;
		mPtr = new int[mArraySize] {};

		// element wise copy
		for (auto element{ 0 }; element < mArraySize; element++) {
			mPtr[element] = arr.mPtr[element];
		}
	}
}

Array& Array::operator=(Array const& rhs)
{
	if (mPtr != rhs.mPtr) {
		mArraySize = rhs.mArraySize;
		// memory allocation
		mPtr = nullptr;
		mPtr = new int[mArraySize] {};
		// elementwise copy
		for (auto index{ 0 }; index < rhs.Size(); index++) {
			mPtr[index] = rhs.mPtr[index];
		}	
	}
	return *this;
}

Array::Array(Array&& arr) noexcept
{
	mArraySize = std::move(arr.mArraySize);
	mPtr = std::move(arr.mPtr);
	// let arr be in a safe state (default state)
	arr.mArraySize = 0;
	arr.mPtr = nullptr;
}

Array& Array::operator=(Array&& arr)
{
	if (this != &arr) {
		mArraySize = std::move(arr.mArraySize);
		mPtr = std::move(arr.mPtr);

		// 
		arr.mArraySize = 0;
		arr.mPtr = nullptr;
	}
	return *this;
}

//void Array::add_value(int index, int value) {
//	mPtr[index] = value;
//}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
	if (arr.IsEmpty()) {
		os << "Empty Array\n";
	}
	else {
		os << "[";
			for (int i{ 0 }; i < arr.Size(); i++) {
			os << arr[i] << " ";
		}
		os << "]\n";
	}

	return os;
}