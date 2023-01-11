#include "../include/Skat.hpp"

#include <iostream>

int     main(void)
{
    Skat    skat;

    std::cout << "Skat.getName = " << skat.getName() << std::endl;
    std::cout << "Skat.getStimPaks = " << skat.getStimPaks() << std::endl;
    return 0;
}