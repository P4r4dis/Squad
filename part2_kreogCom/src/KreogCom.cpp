#include "../include/KreogCom.hpp"
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

int     KreogCom::getSerial(void) const
{
    return m_serial;
}

int     KreogCom::getX(void)
{
    return _x;
}

int     KreogCom::getY(void)
{
    return _y;
}
