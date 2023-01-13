#include "../include/KreogCom.hpp"

#include <iostream>

int     main(void)
{
    KreogCom    kreogCom(42, 42, 202020);

    std::cout << "KreogCom.getSerial = " << kreogCom.getSerial() << std::endl;
    std::cout << "KreogCom.getX = " << kreogCom.getX() << std::endl;
    std::cout << "KreogCom.getY = " << kreogCom.getY() << std::endl;

    std::cout << "KreogCom.addCom :" << std::endl;
    kreogCom.addCom(56, 25, 65);
    std::cout   << "KreogCom.getSerial After add new Com = " 
                << kreogCom.getCom()->getSerial() << std::endl;
    std::cout   << "KreogCom.getX After add new Com = " 
                << kreogCom.getCom()->getX() << std::endl;
    std::cout   << "KreogCom.getY After add new Com = " 
                << kreogCom.getCom()->getY() << std::endl;
    kreogCom.addCom(73, 34, 51);

    std::cout << "KreogCom.ping :" << std::endl;
    kreogCom.ping();

    std::cout << "KreogCom.locateSquad = " << std::endl;
    kreogCom.locateSquad();

    std::cout << "KreogCom destruction :" << std::endl;
    kreogCom.removeCom();
    kreogCom.removeCom();

    std::cout << std::endl;
    std::cout << "REAL MAIN STARTiNG :" << std::endl;
    KreogCom    k(42, 42, 101010);

    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);

    k.locateSquad();

    k.removeCom();
    k.removeCom();

    
    return 0;
}