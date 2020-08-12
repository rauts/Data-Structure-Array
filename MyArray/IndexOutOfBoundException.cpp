#include "IndexOutOfBoundException.h"

const char* IndexOutOfBoundException::what() const noexcept
{
	return "Exception: IndexOutOfBound";
}