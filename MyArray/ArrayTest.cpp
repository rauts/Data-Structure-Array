#include <iostream>
using std::cout;

#include <cassert>
#include "ArrayTest.h"
#include "Array.h"

void TestDefaultConstructor(){
	Array arr{};	
	assert((arr.Size() == 0), "Default constructor should have a zero mArraySize!");
	assert((arr.IsmPtrNull() == true), "Default constructor should have a null mPtr!");
	cout << "\n--------------------------------------\n";
	cout << "Default Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";
}

void TestDestructor() {}