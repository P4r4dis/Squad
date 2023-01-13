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

    KoalaBot        koalaBot;
    koalaBot.setParts(arms);
    std::cout   << std::boolalpha << "KoalaBot set Arms :\n"
                << "KoalaBot Arms's serial = " 
                << koalaBot.getArms().serial() << std::endl
                << "KoalaBot Arms is functional = "
                << koalaBot.getArms().isFunctional() << std::endl
                << "KoalaBot Arms informations : " << std::endl;
    koalaBot.getArms().informations();

    koalaBot.setParts(legs);
    std::cout   << std::boolalpha << "KoalaBot set Legs :\n"
                << "KoalaBot Legs's serial = " 
                << koalaBot.getLegs().serial() << std::endl
                << "KoalaBot Legs is functional = "
                << koalaBot.getLegs().isFunctional() << std::endl
                << "KoalaBot Legs informations : " << std::endl;
    koalaBot.getLegs().informations();

    koalaBot.setParts(head);
    std::cout   << std::boolalpha << "KoalaBot set Head :\n"
                << "KoalaBot Head's serial = " 
                << koalaBot.getHead().serial() << std::endl
                << "KoalaBot Head is functional = "
                << koalaBot.getHead().isFunctional() << std::endl
                << "KoalaBot Head informations : " << std::endl;
    koalaBot.getHead().informations();

    std::cout << "KoalaBot.swapParts :" << std::endl;
    koalaBot.swapParts(head_ko);
    std::cout   << std::boolalpha << "KoalaBot set Head :\n"
                << "KoalaBot Head's serial = " 
                << koalaBot.getHead().serial() << std::endl
                << "KoalaBot Head is functional = "
                << koalaBot.getHead().isFunctional() << std::endl
                << "KoalaBot Head informations : " << std::endl;
    koalaBot.getHead().informations();

    return 0;
}