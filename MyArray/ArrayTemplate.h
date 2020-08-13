#pragma once

#include<iostream>

#include "IndexOutOfBoundException.h"

// First create a class for integer type data. Once it works with an 
// integer data type then change the class to class template for generic
// data type.
template<class T>
class Array
{
private:

	// declare data members

	int mArraySize{ 0 };
	T* mPtr{ nullptr }; // integer pointer pointing to nothing; it needs an address

	bool  IsArrayIndexValid(T index) const {
		return (index >= 0) && (index < mArraySize);
	}

public:

	// default constructor

	Array() = default;

	// parameterized constructor

	explicit Array(int size) {
		if (size != 0) {
			mArraySize = size;
			mPtr = new T[mArraySize] {};
		}
	
	}

	// destructor

	~Array() {
		delete[] mPtr;
	}


	// define public interface

	int Size() const {
		return mArraySize;
	}

	bool IsEmpty() const {
		return (mArraySize == 0) && (mPtr == nullptr);
	}

	void PrintArray() const {
		// TO DO: display the elements of an array
	}
	bool IsmPtrNull() const {
		return mPtr == nullptr;
	}

	// define Array properties
	T operator [](int index) const {
		try {
			if (!IsArrayIndexValid(index)) {
				throw IndexOutOfBoundException();
			}
		}
		catch (std::exception& e) {
			std::cout << e.what();
			// terminate the application
			exit(0); // need a better way to handle the exception 
		}
		catch (...) {
			std::cout << "Unknown exception is caught!\n";
			// terminate the application
			exit(0); // need a better way to handle the exception 
		}


		return mPtr[index];
	}


	T& operator [](int index) {
		try {
			if (!IsArrayIndexValid(index)) {

				throw IndexOutOfBoundException();
				//throw std::range_error("Array Index Out of Bound");
			}
		}
		catch (std::exception& e) {
			std::cout << e.what();
			// terminate the application
			exit(0); // need a better way to handle the exception 

		}
		catch (...) {
			std::cout << "Unknown exception is caught!\n";
			// terminate the application
			exit(0); // need a better way to handle the exception 
		}

		return mPtr[index];
	}

	// copy constructors
	Array(Array const& arr) {
		// allocate memory
		if (!arr.IsEmpty()) {
			mArraySize = arr.mArraySize;
			mPtr = nullptr;
			mPtr = new T[mArraySize] {};

			// element wise copy
			for (int element{ 0 }; element < mArraySize; element++) {
				mPtr[element] = arr.mPtr[element];
			}
		}
	}

	// copy assignment operator
	Array& operator = (Array const& rhs) {
		if (this != &rhs) {
			mArraySize = rhs.mArraySize;
			// memory allocation
			mPtr = nullptr;
			mPtr = new T[mArraySize] {};
			// elementwise copy
			for (int index{ 0 }; index < rhs.Size(); index++) {
				mPtr[index] = rhs.mPtr[index];
			}
		}
		return *this;
	}

	// move constructor
	Array(Array&& arr) noexcept {
		mArraySize = std::move(arr.mArraySize);
		mPtr = std::move(arr.mPtr);
		// let arr be in a safe state (default state)
		arr.mArraySize = 0;
		arr.mPtr = nullptr;
	}

	// move assignment
	Array& operator= (Array&& arr) noexcept {
		if (this != &arr) {
			mArraySize = std::move(arr.mArraySize);
			mPtr = std::move(arr.mPtr);

			// 
			arr.mArraySize = 0;
			arr.mPtr = nullptr;
		}
		return *this;
	
	}

};

template <class P>
std::ostream& operator <<(std::ostream& os, const Array<P>& arr) {
	if (arr.IsEmpty()) {
		os << "Empty Array\n";
	}
	else {
		os << "[";
		for (auto i{ 0 }; i < arr.Size(); i++) {
			os << arr[i] << " ";
		}
		os << "]\n";
	}

	return os;
}