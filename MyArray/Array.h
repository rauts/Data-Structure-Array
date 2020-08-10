#pragma once

#include<iostream>

// First create a class for integer type data. Once it works with an 
// integer data type then change the class to class template for generic
// data type.
 
class Array
{
private:
	
	// declare data members
	
	int mArraySize{};
	int* mPtr{ nullptr };

public:
	
	// default constructor
	
	Array() = default;

	// parameterized constructor

	Array(int size);

	// destructor

	~Array();

		 
	// define public interface
	
	int Size() const;
	bool IsEmpty() const;
	void PrintArray() const;
	bool IsmPtrNull() const;

	//friend std::ostream& operator <<(std::ostream& os, const Array& arr);

};

