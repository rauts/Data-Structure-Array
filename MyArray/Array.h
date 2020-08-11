#pragma once

#include<iostream>

// First create a class for integer type data. Once it works with an 
// integer data type then change the class to class template for generic
// data type.
 
class Array
{
private:
	
	// declare data members
	
	int mArraySize{0};
	int* mPtr{ nullptr }; // integer pointer pointing to nothing; it needs an address

public:
	
	// default constructor
	
	Array() = default;

	// parameterized constructor

	explicit Array(int size);

	// destructor

	~Array();

		 
	// define public interface
	
	int Size() const;
	bool IsEmpty() const;
	void PrintArray() const;
	bool IsmPtrNull() const;

	// define Array properties
	int operator [](const int index) const; // reading
	int& operator [](const int index); // writing
	
	// copy constructors
	Array(Array const& arr);

	// copy assignment operator
	Array& operator = (Array const& arr);

	// move constructor
	Array(Array&& arr) noexcept;

};

std::ostream& operator <<(std::ostream& os, const Array& arr);