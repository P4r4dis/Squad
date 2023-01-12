#include "../include/KoalaBot.hpp"
#include "../include/Parts.hpp"

#include <iostream>

int     main(void)
{
    Parts::Arms     arms;
    Parts::Arms     arms_ko("A-02", false);

    std::cout << "arms.serial = " << arms.serial() << std::endl;
    std::cout   << std::boolalpha << "arms.isFunctional = " 
                << arms.isFunctional() << std::endl;
    arms.informations();
    arms_ko.informations();

    return 0;
}