#include "../include/KreogCom.hpp"

#include <iostream>

int     main(void)
{
    KreogCom    k(42, 42, 101010);

    std::cout << "KreogCom.getSerial = " << k.getSerial() << std::endl;
    std::cout << "KreogCom.getX = " << k.getX() << std::endl;
    std::cout << "KreogCom.getY = " << k.getY() << std::endl;

    std::cout << "KreogCom.addCom :" << std::endl;
    k.addCom(56, 25, 65);
    std::cout   << "KreogCom.getSerial After add new Com = " 
                << k.getCom()->getSerial() << std::endl;
    std::cout   << "KreogCom.getX After add new Com = " 
                << k.getCom()->getX() << std::endl;
    std::cout   << "KreogCom.getY After add new Com = " 
                << k.getCom()->getY() << std::endl;
    k.addCom(73, 34, 51);

    std::cout << "KreogCom destruction :" << std::endl;
    k.removeCom();
    k.removeCom();
    
    return 0;
}