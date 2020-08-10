#include <iostream>
using std::cout;

#include <cassert>
#include "ArrayTest.h"
#include "Array.h"

void TestDefaultConstructor(){
	Array arr{};	
	assert((arr.Size() == 0), "Default constructor does not exist!");
	cout << "\n--------------------------------------\n";
	cout << "Default Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";
}
void TestParametricConstructor() {}
void TestDestructor() {}