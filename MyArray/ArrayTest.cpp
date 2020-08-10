#include <iostream>
using std::cout;

#include <cassert>
#include "ArrayTest.h"
#include "Array.h"

void TestDefaultConstructor(){
	Array arr{};	
	assert(arr.Size() == 0); // , "Default constructor should have a zero ArraySize!");
	assert(arr.IsEmpty()); // , "Default constructor should have a null mPtr!");
	cout << "\n--------------------------------------\n";
	cout << "Default Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";
}

void TestParametricConstructor() {
	Array arr{ 4 };
	assert(arr.Size() == 4); // "Parameterized constructor should have a non-zero mArraySize");
	assert(!arr.IsmPtrNull()); // "Parameterized constructor should have a nonnull mPtr!
	assert(!arr.IsEmpty()); // , "Parameterized constructor should have neither a null mPtr and a zero mArraySize!");
	cout << "\n--------------------------------------\n";
	cout << "Parameterized Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";
}

void TestDestructor() {}