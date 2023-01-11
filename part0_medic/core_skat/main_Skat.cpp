#include "../include/Skat.hpp"

#include <iostream>

int     main(void)
{
    Skat    skat;

    std::cout << "Skat.getName = " << skat.getName() << std::endl;
    std::cout << "Skat.getStimPaks = " << skat.getStimPaks() << std::endl;
    skat.stimPaks() = 5;
    std::cout << "skat.stimPaks = " << skat.stimPaks() << std::endl;
    
    return 0;
}