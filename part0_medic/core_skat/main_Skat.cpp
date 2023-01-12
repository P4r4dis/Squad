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
    skat.addStimPaks(0);
    skat.addStimPaks(15);
    std::cout << "After skat.addStimPaks(number > 0), stimPaks = " << skat.stimPaks() << std::endl;

    skat.stimPaks() = 0;
    std::cout   << "skat.stimPaks = " << skat.stimPaks() 
                << " , Answer will be Mediiiiiic" << std::endl;
    skat.useStimPaks();
    skat.stimPaks() = 15;
    std::cout   << "skat.stimPaks = " << skat.stimPaks() << std::endl;
    skat.useStimPaks();
    std::cout   << "skat.stimPaks after skat.useStimPaks = " << skat.stimPaks() << std::endl;

    skat.status();

    std::cout << "REAL MAIN STARTiNG :" << std::endl;
    Skat    s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    return 0;
}