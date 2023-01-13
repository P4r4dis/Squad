#include "../include/KreogCom.hpp"

#include <iostream>

int     main(void)
{
    KreogCom    k(42, 42, 101010);

    std::cout << "KreogCom.getSerial = " << k.getSerial() << std::endl;
    std::cout << "KreogCom.getX = " << k.getX() << std::endl;
    std::cout << "KreogCom.getY = " << k.getY() << std::endl;
    return 0;
}