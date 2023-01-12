#include "../part0_medic/include/Skat.hpp"

#include <iostream>

int     main(void)
{
    std::cout << "Skat Main Starting---------------------------:" << std::endl;
    Skat    s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    std::cout << "Skat Main Ending------------------------------" << std::endl;

    return 0;
}