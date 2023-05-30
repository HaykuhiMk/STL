#include <iostream>
#include "bitVector.h"

int main()
{
	bitVector bVec;
	bVec.bitSet(12);
	std::cout << "Result = " << bVec << std::endl;
	bVec.bitReset(12);
	std::cout << "Result = " << bVec << std::endl;

}
