#include "../include/Skat.hpp"

#include <iostream>

int     main(void)
{
    Skat    skat;

    std::cout << "Skat.getName = " << skat.name() << std::endl;
    std::cout << "Skat.getStimPaks = " << skat.stimPaks() << std::endl;
    skat.stimPaks() = 5;
    std::cout << "skat.stimPaks = " << skat.stimPaks() << std::endl;

    Skat    skat2("Skat", 50);
    std::cout << "Skat2.getStimPaks before sharing = " << skat2.stimPaks() << std::endl;
    skat.shareStimPaks(4, skat2.stimPaks());
    std::cout << "Skat2.getStimPaks after sharing = " << skat2.stimPaks() << std::endl;
    std::cout   << "Skat.getStimPaks after sharing with Skat2 = " 
                << skat.stimPaks() << std::endl;
    std::cout << "Skat2.getStimPaks before sharing = " << skat2.stimPaks() << std::endl;
    skat.shareStimPaks(1, skat2.stimPaks());
    std::cout << "Don't be greedy = nothing to change" << std::endl;
    std::cout << "Skat2.getStimPaks after sharing = " << skat2.stimPaks() << std::endl;
    std::cout   << "Skat.getStimPaks after sharing with Skat2 = " 
                << skat.stimPaks() << std::endl;

    
    return 0;
}