#include "../test_include/test_KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial) :  _x(x), _y(y),
                                                m_serial(serial)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom(void)
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

int         KreogCom::getSerial(void) const
{
    return m_serial;
}

int         KreogCom::getX(void)
{
    return _x;
}

int         KreogCom::getY(void)
{
    return _y;
}

void        KreogCom::addCom(int x, int y, int serial)
{
    // Create a new KreogCom with the given x, y, and serial values
    KreogCom    *newKreogCom = new KreogCom(x, y, serial);

    // Get the current next KreogCom
    KreogCom    *oldKreogCom = getCom();

    // If there is already a next KreogCom
    if (oldKreogCom != nullptr) {
        // Link the new KreogCom to the old one
        newKreogCom->_next = oldKreogCom;
    }
    // Link the new KreogCom to the current one
    _next = newKreogCom;
}

// void        KreogCom::addComSmartPtr(int x, int y, int serial)
// {
//     // Create a new KreogCom with the given x, y, and serial values
//     std::unique_ptr<KreogCom> newKreogCom = std::make_unique<KreogCom>(x, y, serial);

//     // Get the current next KreogCom
//     std::unique_ptr<KreogCom> oldKreogCom = std::move(m_next);

//     // Link the new KreogCom to the current one
//     m_next = std::move(newKreogCom);
// }

KreogCom    *KreogCom::getCom(void)
{
    return _next;
}

// std::unique_ptr<KreogCom>   KreogCom::getUniquePtrCom(void)
// {
//     return std::move(m_next);
// }