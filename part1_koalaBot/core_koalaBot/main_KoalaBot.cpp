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

    Parts::Legs     legs;
    Parts::Legs     legs_ko("L-02", false);

    std::cout << "legs.serial = " << legs.serial() << std::endl;
    std::cout   << std::boolalpha << "legs.isFunctional = " 
                << legs.isFunctional() << std::endl;
    legs.informations();
    legs_ko.informations();
    
    Parts::Head     head;
    Parts::Head     head_ko("H-02", false);

    std::cout << "head.serial = " << head.serial() << std::endl;
    std::cout   << std::boolalpha << "head.isFunctional = " 
                << head.isFunctional() << std::endl;
    head.informations();
    head_ko.informations();


    return 0;
}