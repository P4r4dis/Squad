#include "../include/Phaser.hpp"

#include <iostream>

int     main(void)
{
    Phaser phaser;
    std::cout << "pahser.getCurrentAmmos = " << phaser.getCurrentAmmos() << std::endl;
    std::cout << "phaser.getEmpty = " << phaser.getEmpty() << std::endl;
    std::cout << "phaser.getAmmoType = " << phaser.getAmmoType() << std::endl;
    return 0;
}