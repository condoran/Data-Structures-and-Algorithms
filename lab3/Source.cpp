#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>

int main()
{
	testAll();
	std::cout << "short tested!" << std::endl;
	testAllExtended();
	std::cout << "extended tested!" << std::endl;
}