#include "../test_include/test_Phaser.hpp"

#include <iostream>


Phaser::Phaser(int maxAmmo, AmmoType type) :    _maxAmmo(maxAmmo), _type(type)
{}

Phaser::~Phaser(void)
{}

int                 Phaser::getCurrentAmmos(void)
{
    return _maxAmmo;
}

int                 Phaser::getEmpty(void) const
{
    return Empty;
}

Phaser::AmmoType    Phaser::getAmmoType(void)
{
    return _type;
}

const std::string Sounds::Regular = "PiouPiouu";
const std::string Sounds::Plasma  = "Pffiizzzz";
const std::string Sounds::Rocket  = "Booooooom";

void                Phaser::fire(void)
{
    if (getCurrentAmmos() == getEmpty())
        std::cout << "Clip empty, please reload" << std::endl;
    else
    {
        if (_type == REGULAR)
            std::cout << Sounds::Regular << std::endl;
        else if (_type == PLASMA)
            std::cout << Sounds::Plasma << std::endl;
        else
            std::cout << Sounds::Rocket << std::endl;
        _maxAmmo--;
    }
}

void                Phaser::ejectClip(void)
{
    _maxAmmo = 0;
}