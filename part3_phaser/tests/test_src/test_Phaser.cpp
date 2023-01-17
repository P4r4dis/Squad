#include "../test_include/test_Phaser.hpp"

#include <iostream>


Phaser::Phaser(int maxAmmo, AmmoType type) :    _maxAmmo(maxAmmo), _type(type),
                                                _currentAmmo(maxAmmo)
{
    for (int i = 0; i < _currentAmmo; i++) {
        _magazine.push_back(_type);
    }
}

Phaser::~Phaser(void)
{}

std::vector<Phaser::AmmoType>    Phaser::getMagazine(void)
{
    return _magazine;
}

int                 Phaser::getMaxAmmos(void)
{
    return _maxAmmo;
}

int                 Phaser::getCurrentAmmos(void)
{
    return _currentAmmo;
}

int                 Phaser::getEmpty(void) const
{
    return Empty;
}

Phaser::AmmoType    Phaser::getAmmoType(void)
{
    return _type;
}


// Phaser::AmmoType    Phaser::getDefaultAmmoType(void)
// {
//     return _defaultType;
// }

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
        // _maxAmmo--;
        _currentAmmo--;
        _magazine.erase(_magazine.begin());
    }
}

void                Phaser::ejectClip(void)
{
    _currentAmmo = Empty;
    // _magazine.clear();
    _magazine.erase(_magazine.begin(), _magazine.end());
}

void                Phaser::changeType(AmmoType newType)
{
    if (newType == REGULAR)
    {
        _type = newType;
        std::cout << "Switching ammo to type: regular" << std::endl;
    }
    else if (newType == PLASMA)
    {
        _type = newType;
        std::cout << "Switching ammo to type: plasma" << std::endl;       
    }
    else
    {
        _type = newType;
        std::cout << "Switching ammo to type: rocket" << std::endl;          
    }
}

void                Phaser::reload(void)
{
    std::cout << "Reloading..." << std::endl;
    ejectClip();
    _currentAmmo = _maxAmmo;
    for(int i = 0; i < _currentAmmo; i++)
        _magazine.push_back(_type);
}
