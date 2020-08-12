#include "IndexOutOfBoundException.h"

const char* IndexOutOfBoundException::what() const noexcept
{
	return "\nException: IndexOutOfBound\n";
}