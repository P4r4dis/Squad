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
    return 0;
}