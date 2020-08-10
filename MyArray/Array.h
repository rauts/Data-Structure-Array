#pragma once
// First create a class for integer type data. Once it works with integer data
// type then change the class to class template for generic data type.
// 
class Array
{
private:
	
	// declare data members
	
	int mSize{};
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
	bool isEmpty() const;
	void PrintArray() const;

};

