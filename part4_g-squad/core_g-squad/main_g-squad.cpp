#include "../include/Skat.hpp"
#include "../include/KoalaBot.hpp"
#include "../include/Parts.hpp"
// #include "../include/KreogCom.hpp"
// #include "../include/Phaser.hpp"

#include <iostream>

int     main(void)
{
    Skat    skat;
    std::cout   << "skat.getName = " << skat.name() << std::endl;
    std::cout   << "skat.getStimPaks = " << skat.stimPaks() << std::endl;
    std::cout   << "skat.getKreogCom.getSerial = " 
                << skat.getKreogCom().getSerial() << std::endl;
    std::cout   << "skat.getKreogCom.getX = " 
                << skat.getKreogCom().getX() << std::endl;
    std::cout   << "skat.getKreogCom.getY = " 
                << skat.getKreogCom().getY() << std::endl;
    std::cout   << "skat.getPhaser.getMaxAmmo = " 
                << skat.getPhaser().getMaxAmmos() << std::endl;
    std::cout   << "skat.getPhaser.getAmmoType = " 
                << skat.getPhaser().getAmmoType() << std::endl;

    std::cout   << "skat.fire = ";
    skat.fire();
    std::cout   << "skat.locate = ";
    skat.locate();
    std::cout   << "Skat.reload = ";
    skat.reload();

    std::cout   << "Skat.com for get X position = " 
                << skat.com().getX() << std::endl;
    
    std::cout   << "KreogCom.addCom(KreogCom *ptr) = ";
    KreogCom k1(1, 2, 3);
    std::cout   << "k1.getX = " << k1.getX() << ", ";
    KreogCom k2(4, 5, 6);
    k1.addCom(&k2);
    std::cout   << "k1.getCom().getX() = " << k1.getCom()->getX() << std::endl;


    return 0;
}