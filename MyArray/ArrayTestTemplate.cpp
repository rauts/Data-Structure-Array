#include <iostream>
using std::cout;

#include <cassert>
#include "ArrayTestTemplate.h"
#include "ArrayTemplate.h"



void TestDefaultConstructor() {
	Array<float> arr{};
	assert(arr.Size() == 0); // , "Default constructor should have a zero ArraySize!");
	assert(arr.IsEmpty()); // , "Default constructor should have a null mPtr!");
	cout << "\n--------------------------------------\n";
	cout << "Default Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";
}

void TestParametricConstructor() {
	Array<float> arr{ 4 };
	assert(arr.Size() == 4); // "Parameterized constructor should have a non-zero mArraySize");
	assert(!arr.IsmPtrNull()); // "Parameterized constructor should have a nonnull mPtr!
	assert(!arr.IsEmpty()); // , "Parameterized constructor should have neither a null mPtr and a zero mArraySize!");
	cout << "\n--------------------------------------\n";
	cout << "Parameterized Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";
}

void TestSquareBracketOperator() {
	Array <float> arr{ 3 };
	if (arr.Size() > 0) {
		for (int element{ 0 }; element < arr.Size(); element++) {
			arr[element] = element;
		}
	}
	assert(arr[2] == 2);

	cout << "\n--------------------------------------\n";
	cout << "[] Operator Test: Passed!";
	cout << "\n--------------------------------------\n";

}

void TestIndirectionOperator() {
	Array<float> arr{ 5 };
	if (arr.Size() > 0) {
		for (int element{ 0 }; element < arr.Size(); element++) {
			arr[element] = element;
		}
	}
	assert(arr[0] == 0);
	cout << "Before arr = " << arr << '\n';
	arr[0] = 10.50;
	assert(arr[0] == 10.50);
	cout << "arr[0] = 10.50" << '\n';
	cout << "\nAfter arr = " << arr << '\n';

	cout << "\n--------------------------------------\n";
	cout << "<< Operator Test: Passed!";
	cout << "\n--------------------------------------\n";
}

void TestCopyConstructor() {
	Array <float>arr{ 3 };
	if (arr.Size() > 0) {
		for (int element{ 0 }; element < arr.Size(); element++) {
			arr[element] = element + 1;
		}
	}
	assert(arr[0] == 1.0);

	cout << "Before arr = " << arr << '\n';

	Array arr2{ arr };
	
	assert(arr2[1] == 2.0);
	cout << "After copy constructor arr2 = " << arr2 << '\n';


	cout << "\n--------------------------------------\n";
	cout << "Copy Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";

}

void TestAssignmentOperator() {
	Array<float> arr{ 3 };
	if (arr.Size() > 0) {
		for (auto element{ 0 }; element < arr.Size(); element++) {
			arr[element] = element + 1;
		}
	}
	assert(arr[0] == 1.0);
	assert(!arr.IsEmpty());

	cout << "Before arr = " << arr << '\n';

	Array <float> arr2{};
	arr2 = arr;
	assert(!arr2.IsEmpty());
	assert(arr2[1] == 2.0);
	assert(arr2.Size() == arr.Size());
	cout << "After assignement operator arr2 = " << arr2 << '\n';


	cout << "\n--------------------------------------\n";
	cout << "Assignment Operator (=) Test: Passed!";
	cout << "\n--------------------------------------\n";

}

void TestMoveConstructor() {
	Array<float> arr{ 3 };
	if (arr.Size() > 0) {
		for (auto element{ 0 }; element < arr.Size(); element++) {
			arr[element] = element + 1;
		}
	}
	assert(arr[0] == 1);
	assert(!arr.IsEmpty());

	cout << "Before arr = " << arr << '\n';

	Array<float> arr2{ std::move(arr) };
	assert(!arr2.IsEmpty());
	assert(arr2[1] == 2.0);
	assert(arr.IsEmpty());

	cout << "After move constructor arr2 = " << arr2 << '\n';


	cout << "\n--------------------------------------\n";
	cout << "Move Constructor Test: Passed!";
	cout << "\n--------------------------------------\n";

}

void TestMoveAssignmentOperator()
{
	Array<float> arr{ 3 };
	if (arr.Size() > 0) {
		for (auto element{ 0 }; element < arr.Size(); element++) {
			arr[element] = element + 1;
		}
	}
	assert(arr[0] == 1.0);
	assert(!arr.IsEmpty());

	cout << "Before arr = " << arr << '\n';

	Array <float>arr2{};
	arr2 = std::move(arr); // move assignment operator is called
	assert(!arr2.IsEmpty());
	assert(arr2[1] == 2.0);
	assert(arr.IsEmpty());
	cout << "After move assignement operator arr2 = " << arr2 << '\n';

	cout << "\n--------------------------------------\n";
	cout << "Move Assignment Operator Test: Passed!";
	cout << "\n--------------------------------------\n";
}

void TestIndexOutOfBoundException() {
	Array <float> arr{ 2 };
	arr[0] = 1.236;
	arr[1] = 2.58;
	//assert(arr[0] == 1.236);
	assert(!arr.IsEmpty());
	assert(arr.Size() == 2);

	cout << "Before arr = " << arr << '\n';

	cout << "arr[3] = 5.15 \n";
	// cause out of range error
	arr[3] = 5.15;
}
