#include "../part0_medic/include/Skat.hpp"
#include "../part1_koalaBot/include/KoalaBot.hpp"
#include <iostream>

int     main(void)
{
    std::cout << "Skat Main Starting---------------------------:" << std::endl;
    Skat        s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    std::cout << "Skat Main Ending------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "KoalaBot Main Starting---------------------------:" << std::endl;
    KoalaBot    kb;
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    std::cout << "KoalaBot Main Ending------------------------------" << std::endl;
    std::cout << std::endl;
    return 0;
}