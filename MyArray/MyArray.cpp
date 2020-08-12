// MyArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;


#include <memory> // for shared_ptr and make_shared
using std::make_shared;
using std::shared_ptr;

#include "Array.h"
#include "ArrayTest.h"

int main()
{
    //TestDefaultConstructor();

    //TestParametricConstructor();
    //
    //TestSquareBracketOperator(); // []

    //TestIndirectionOperator(); // <<

    //TestCopyConstructor();

    //TestAssignmentOperator();

    //TestMoveConstructor();

    // TestMoveAssignmentOperator();

    TestIndexOutOfBoundException();

    //shared_ptr<int> myArray(new int[5], std::default_delete<int[]>());
    //myArray.get()[0] = 0;
    //myArray.get()[2] = 2;
    //myArray.get()[1] = 1;
    //cout << myArray.get()[2] << '\n';



    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
