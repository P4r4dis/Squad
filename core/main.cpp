#include "../part0_medic/include/Skat.hpp"
#include "../part1_koalaBot/include/KoalaBot.hpp"
#include "../part2_kreogCom/include/KreogCom.hpp"
#include "../part3_phaser/include/Phaser.hpp"

#include <iostream>

int     main(void)
{
    std::cout << "Skat Main Starting---------------------------:" << std::endl;
    Skat        s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    std::cout << "Skat Main Ending------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "KoalaBot Main Starting---------------------------:" << std::endl;
    KoalaBot    kb;
    std::cout << std::boolalpha << kb.status() << std::endl;
    kb.informations();
    std::cout << "KoalaBot Main Ending------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "KreogCom Main Starting---------------------------:" << std::endl;
    KreogCom    k(42, 42, 101010);
    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k.locateSquad();
    k.removeCom();
    k.removeCom();
    std::cout << "KreogCom Main Ending------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Phaser Main Starting---------------------------:" << std::endl;
    Phaser  p(5, Phaser::ROCKET);

    p.fire();
    p.reload();

    std::cout << "Firing all ammunitions" << std::endl;
    while(p.getCurrentAmmos () > 0)
        p.fire();
    std::cout << "Phaser Main Ending------------------------------" << std::endl;
    return 0;
}