#pragma once
#include <exception>

class IndexOutOfBoundException: public std::exception
{
	const char* what() const noexcept;
	/*{
		return "IndexOutOfBoundException";
	}*/

};

