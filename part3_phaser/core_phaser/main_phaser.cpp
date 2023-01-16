#include "../include/Phaser.hpp"

#include <iostream>

int     main(void)
{
    Phaser phaser;
    std::cout << "pahser.getCurrentAmmos = " << phaser.getCurrentAmmos() << std::endl;
    std::cout << "phaser.getEmpty = " << phaser.getEmpty() << std::endl;
    std::cout << "phaser.getAmmoType = " << phaser.getAmmoType() << std::endl;
    std::cout << "phaser.fire = ";
    phaser.fire();
    std::cout << "phaser.getCurrentAmmos after fire = " << phaser.getCurrentAmmos() << std::endl;

    return 0;
}