#include "../include/Phaser.hpp"

#include <iostream>

int     main(void)
{
    Phaser phaser(1, Phaser::REGULAR);
    std::cout << "pahser.getCurrentAmmos = " << phaser.getCurrentAmmos() << std::endl;
    std::cout << "phaser.getEmpty = " << phaser.getEmpty() << std::endl;
    std::cout << "phaser.getAmmoType = " << phaser.getAmmoType() << std::endl;
    std::cout << "phaser.fire = ";
    phaser.fire();
    std::cout << "phaser.getCurrentAmmos after fire = " << phaser.getCurrentAmmos() << std::endl;
    std::cout << "2e phaser.fire = ";
    phaser.fire();
    std::cout << "phaser.getCurrentAmmos after fire = " << phaser.getCurrentAmmos() << std::endl;
    Phaser phaser2;
    std::cout << "phaser2.getCurrentAmmos = " << phaser2.getCurrentAmmos() << std::endl;
    phaser2.ejectClip();
    std::cout << "phaser2.getCurrentAmmos after ejectClip = " << phaser2.getCurrentAmmos() << std::endl;

    return 0;
}