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