#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "test_include/test_Phaser.hpp"
#include "test_include/test_Skat.hpp"
#include "test_include/test_KoalaBot.hpp"
#include "test_include/test_Parts.hpp"
#include "test_include/test_KreogCom.hpp"


#include <iostream>

// Test(Skat, test_skat_construction)
// {
//     Skat    skat;

//     cr_assert(skat.getName() == "bob");
//     cr_assert(skat.getStimPaks() == 15);

//     Skat    skat2("SKAT", 50);
//     cr_assert(skat2.getName() == "SKAT");
//     cr_assert(skat2.getStimPaks() == 50);   
// }

// Test(Skat, test_stimPaks)
// {
//     Skat    skat;

//     cr_assert(skat.getName() == "bob");
//     cr_assert(skat.getStimPaks() == 15);

//     Skat    skat2("SKAT", 50);
//     cr_assert(skat2.getName() == "SKAT");
//     cr_assert(skat2.getStimPaks() == 50);

//     skat2.stimPaks() = 5;
//     cr_assert(skat2.stimPaks() == 5);
//     cr_assert(skat2.getStimPaks() == 5);
// }

// Test(Skat, test_name)
// {
//     Skat    skat;

//     cr_assert(skat.name() == "bob");
// }

// Test(Skat, test_shareStimPaks, .init=redirect_all_stdout)
// {
//     Skat    skat;
//     Skat    skat2("SKAT", 50);

//     cr_assert(skat2.getStimPaks() == 50);
//     skat.shareStimPaks(10, skat2.stimPaks());
//     cr_assert(skat2.stimPaks() == 60);
//     cr_assert(skat.stimPaks() == 5);
//     cr_assert_stdout_eq_str("Keep the change.\n");
// }

// Test(Skat, test_shareStimPaks_greedy, .init=redirect_all_stdout)
// {
//     Skat    skat;
//     Skat    skat2("SKAT", 50);

//     cr_assert(skat2.getStimPaks() == 50);
//     skat.shareStimPaks(20, skat2.stimPaks());
//     cr_assert(skat2.stimPaks() == 50);
//     cr_assert(skat.stimPaks() == 15);
//     cr_assert_stdout_eq_str("Don't be greedy\n");
// }

// Test(Skat, test_addStimPaks_zero, .init=redirect_all_stdout)
// {
//     Skat    skat;

//     skat.addStimPaks(0);
//     cr_assert(skat.getStimPaks() == 15);
//     cr_assert_stdout_eq_str("Hey boya, did you forget something?\n");
// }

// Test(Skat, test_addStimPaks)
// {
//     Skat    skat;

//     skat.addStimPaks(10);
//     cr_assert(skat.getStimPaks() == 25);
// }

// Test(Skat, test_useStimPaks_zero, .init=redirect_all_stdout)
// {
//     Skat    skat;

//     cr_assert(skat.stimPaks() == 15);
//     skat.stimPaks() = 0;
//     cr_assert(skat.stimPaks() == 0);

//     skat.useStimPaks();
//     cr_assert_stdout_eq_str("Mediiiiiic\n");
// }

// Test(Skat, test_useStimPaks, .init=redirect_all_stdout)
// {
//     Skat    skat;

//     cr_assert(skat.stimPaks() == 15);
//     skat.useStimPaks();
//     cr_assert(skat.stimPaks() == 14);
//     cr_assert_stdout_eq_str("Time to kick some ass and chew bubble gum.\n");
// }

// Test(Skat, test_status, .init=redirect_all_stdout)
// {
//     Skat    skat;
    
//     skat.status();
//     cr_assert_stdout_eq_str("Soldier bob reporting 15 stimpaks remaining sir!\n");
// }

// Test(Skat, test_skat_main, .init=redirect_all_stdout)
// {
//     Skat    s("Junior", 5);
//     std::cout << "Soldier " << s.name() << std::endl;
//     s.status();
//     s.useStimPaks();
//     cr_assert_stdout_eq_str("Soldier Junior\n
// Soldier Junior reporting 5 stimpaks remaining sir!\n
// Time to kick some ass and chew bubble gum.\n");
// }

Test(Skat, test_skat_construction)
{
    Skat    skat("bob", 15, 101010, 10, 10, Phaser::ROCKET);

    cr_assert(skat.getName() == "bob");
    cr_assert(skat.getStimPaks() == 15);
    cr_assert(skat.getKreogCom().getSerial() == 101010);
    cr_assert(skat.getKreogCom().getX() == 10);
    cr_assert(skat.getKreogCom().getY() == 10);
    cr_assert(skat.getPhaser().getAmmoType() == Phaser::ROCKET);
}

Test(Skat, test_skat_fire, .init = redirect_all_stdout)
{
    Skat    skat("bob", 15, 101010, 10, 10, Phaser::ROCKET);

    skat.fire();
    cr_assert(skat.getPhaser().getCurrentAmmos() == 19);
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\nBooooooom\n");
}

////////////////////////////////////////////////////

Test(Parts_Arms, test_Arms_ctor)
{  
    Parts::Arms     arms;

    cr_assert(arms.isFunctional() == true);
    cr_assert(arms.serial() == "A-01");
}

Test(Parts_Arms, test_Arms_informations_OK, .init=redirect_all_stdout)
{  
    Parts::Arms     arms;

    arms.informations();
    cr_assert_stdout_eq_str("\t[Parts] Arms A-01 status : OK\n");
}

Test(Parts_Arms, test_Arms_informations_KO, .init=redirect_all_stdout)
{  
    Parts::Arms     arms("A-01", false);

    arms.informations();
    cr_assert_stdout_eq_str("\t[Parts] Arms A-01 status : KO\n");
}
/// LEGS //////////////////////////////////////////////////////////////  
Test(Parts_Legs, test_Legs_ctor)
{  
    Parts::Legs     legs;

    cr_assert(legs.isFunctional() == true);
    cr_assert(legs.serial() == "L-01");
}

Test(Parts_Legs, test_Legs_informations_OK, .init=redirect_all_stdout)
{  
    Parts::Legs     legs;

    legs.informations();
    cr_assert_stdout_eq_str("\t[Parts] Legs L-01 status : OK\n");
}

Test(Parts_Legs, test_Legs_informations_KO, .init=redirect_all_stdout)
{  
    Parts::Legs     legs("L-01", false);

    legs.informations();
    cr_assert_stdout_eq_str("\t[Parts] Legs L-01 status : KO\n");
}

/// HEAD //////////////////////////////////////////////////////////////  

Test(Parts_Head, test_Head_ctor)
{  
    Parts::Head     head;

    cr_assert(head.isFunctional() == true);
    cr_assert(head.serial() == "H-01");
}

Test(Parts_Head, test_Head_informations_OK, .init=redirect_all_stdout)
{  
    Parts::Head     head;

    head.informations();
    cr_assert_stdout_eq_str("\t[Parts] Head H-01 status : OK\n");
}

Test(Parts_Head, test_Head_informations_KO, .init=redirect_all_stdout)
{  
    Parts::Head     head("H-01", false);

    head.informations();
    cr_assert_stdout_eq_str("\t[Parts] Head H-01 status : KO\n");
}
////////////////////////////////////////////////////////////////////////
//KOALABOT

Test(KoalaBot, test_KoalaBot_ctor)
{
    Parts::Arms     arms;
    Parts::Legs     legs;
    Parts::Head     head;

    KoalaBot        koalaBot;
    koalaBot.setParts(arms);
    koalaBot.setParts(legs);
    koalaBot.setParts(head);
    cr_assert(koalaBot.getSerial() == "Bob-01");
    cr_assert(koalaBot.getArms().isFunctional() == true);
    cr_assert(koalaBot.getLegs().isFunctional() == true);
    cr_assert(koalaBot.getHead().isFunctional() == true);
}

Test(KoalaBot, test_KoalaBot_swapParts)
{
    Parts::Arms     arms;
    Parts::Legs     legs;
    Parts::Head     head;

    KoalaBot        koalaBot;
    koalaBot.setParts(arms);
    koalaBot.setParts(legs);
    koalaBot.setParts(head);
    cr_assert(koalaBot.getSerial() == "Bob-01");
    cr_assert(koalaBot.getArms().isFunctional() == true);
    cr_assert(koalaBot.getLegs().isFunctional() == true);
    cr_assert(koalaBot.getHead().isFunctional() == true);

    Parts::Arms     armsToSwap("name1", false);
    Parts::Legs     legsToSwap("namw2", false);
    Parts::Head     headToSwap("name3", false);
    koalaBot.swapParts(armsToSwap);
    koalaBot.swapParts(legsToSwap);
    koalaBot.swapParts(headToSwap);
    cr_assert(koalaBot.getArms().isFunctional() == false);
    cr_assert(koalaBot.getLegs().isFunctional() == false);
    cr_assert(koalaBot.getHead().isFunctional() == false);
}

Test(KoalaBot, test_KoalaBot_informations, .init=redirect_all_stdout)
{
    KoalaBot        koalaBot;

    koalaBot.informations();
    cr_assert_stdout_eq_str("[KoalaBot] Bob-01\n\
\t[Parts] Arms A-01 status : OK\n\
\t[Parts] Legs L-01 status : OK\n\
\t[Parts] Head H-01 status : OK\n");
}


Test(KoalaBot, test_KoalaBot_status_true)
{
    KoalaBot        koalaBot;

    koalaBot.informations();
    cr_assert(koalaBot.status() == true);
}

Test(KoalaBot, test_KoalaBot_status_false)
{
    KoalaBot        koalaBot;
    Parts::Arms     armsToSwap("name1", false);

    koalaBot.swapParts(armsToSwap);
    koalaBot.informations();
    cr_assert(koalaBot.status() == false);
}

Test(KoalaBot, test_KoalaBot_main, .init=redirect_all_stdout)
{
    KoalaBot        koalaBot;

    std::cout << std::boolalpha << koalaBot.status() << std::endl;
    koalaBot.informations();
    cr_assert_stdout_eq_str("true\n\
[KoalaBot] Bob-01\n\
\t[Parts] Arms A-01 status : OK\n\
\t[Parts] Legs L-01 status : OK\n\
\t[Parts] Head H-01 status : OK\n");
}

/////////////////////////////////////////////////////////////////////

Test(KreogCom, test_KreogCom_ctor, .init = redirect_all_stdout)
{  
    KreogCom    k(42, 42, 101010);

    cr_assert(k.getX() == 42);
    cr_assert(k.getY() == 42);
    cr_assert(k.getSerial() == 101010);
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\n");
}

Test(KreogCom, test_KreogCom_dtor, .init = redirect_all_stdout)
{  
    KreogCom    k(42, 42, 101010);

    cr_assert(k.getX() == 42);
    cr_assert(k.getY() == 42);
    cr_assert(k.getSerial() == 101010);
    k.~KreogCom();
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\n\
KreogCom 101010 shutting down\n");
}

Test(KreogCom, test_KreogCom_addCom, .init = redirect_all_stdout)
{  
    KreogCom    k(42, 42, 101010);

    cr_assert(k.getX() == 42);
    cr_assert(k.getY() == 42);
    cr_assert(k.getSerial() == 101010);
    k.addCom(56, 25, 65);
    cr_assert(k.getCom()->getX() == 56);
    k.addCom(73, 34, 51);

    k.~KreogCom();
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\n\
KreogCom 65 initialized\n\
KreogCom 51 initialized\n\
KreogCom 101010 shutting down\n");
}

Test(KreogCom, test_KreogCom_removeCom, .init = redirect_all_stdout)
{  
    KreogCom    k(42, 42, 101010);

    cr_assert(k.getX() == 42);
    cr_assert(k.getY() == 42);
    cr_assert(k.getSerial() == 101010);
    k.addCom(56, 25, 65);
    cr_assert(k.getCom()->getX() == 56);
    k.addCom(73, 34, 51);

    k.removeCom();
    k.removeCom();
    k.~KreogCom();
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\n\
KreogCom 65 initialized\n\
KreogCom 51 initialized\n\
KreogCom 51 shutting down\n\
KreogCom 65 shutting down\n\
KreogCom 101010 shutting down\n");
}

Test(KreogCom, test_KreogCom_ping, .init = redirect_all_stdout)
{  
    KreogCom    k(42, 42, 101010);

    k.ping();
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\n\
KreogCom 101010 currently at 42 42\n");
}

Test(KreogCom, test_KreogCom_locateSquad, .init = redirect_all_stdout)
{  
    KreogCom    k(42, 42, 101010);

    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);

    k.locateSquad();
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\n\
KreogCom 65 initialized\n\
KreogCom 51 initialized\n\
KreogCom 51 currently at 73 34\n\
KreogCom 65 currently at 56 25\n\
KreogCom 101010 currently at 42 42\n");
}

Test(KreogCom, test_KreogCom_main, .init = redirect_all_stdout)
{  
    KreogCom    k(42, 42, 101010);

    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);

    k.locateSquad();

    k.removeCom();
    k.removeCom();
    k.~KreogCom();
    cr_assert_stdout_eq_str("KreogCom 101010 initialized\n\
KreogCom 65 initialized\n\
KreogCom 51 initialized\n\
KreogCom 51 currently at 73 34\n\
KreogCom 65 currently at 56 25\n\
KreogCom 101010 currently at 42 42\n\
KreogCom 51 shutting down\n\
KreogCom 65 shutting down\n\
KreogCom 101010 shutting down\n");
}
//////////////////////////////////////////////////////////////////////

Test(Phaser, test_Phaser_ctor)
{  
    Phaser p;

    cr_assert(p.getCurrentAmmos() == 20);
    cr_assert(p.getEmpty() == 0);
    cr_assert(p.getAmmoType() == Phaser::REGULAR);
    for (int i; i < p.getAmmoType(); i++)
        cr_assert(p.getMagazine()[i] == Phaser::REGULAR);
}

Test(Phaser, test_Phaser_fire_Regular,.init = redirect_all_stdout)
{  
    Phaser p;

    cr_assert(p.getCurrentAmmos() == 20);
    cr_assert(p.getEmpty() == 0);
    cr_assert(p.getAmmoType() == Phaser::REGULAR);

    p.fire();
    cr_assert(p.getCurrentAmmos() == 19);
    cr_assert_stdout_eq_str("PiouPiouu\n");
}

Test(Phaser, test_Phaser_fire_Plasma, .init = redirect_all_stdout)
{  
    Phaser p(20, Phaser::PLASMA);

    cr_assert(p.getCurrentAmmos() == 20);
    cr_assert(p.getEmpty() == 0);
    cr_assert(p.getAmmoType() == Phaser::PLASMA);

    p.fire();
    cr_assert(p.getCurrentAmmos() == 19);
    cr_assert_stdout_eq_str("Pffiizzzz\n");
}

Test(Phaser, test_Phaser_fire_Rocket, .init = redirect_all_stdout)
{  
    Phaser p(20, Phaser::ROCKET);

    cr_assert(p.getCurrentAmmos() == 20);
    cr_assert(p.getEmpty() == 0);
    cr_assert(p.getAmmoType() == Phaser::ROCKET);

    p.fire();
    cr_assert(p.getCurrentAmmos() == 19);
    cr_assert_stdout_eq_str("Booooooom\n");
}

Test(Phaser, test_Phaser_fire_Rocket_empty, .init = redirect_all_stdout)
{  
    Phaser p(1, Phaser::ROCKET);

    cr_assert(p.getCurrentAmmos() == 1);
    cr_assert(p.getEmpty() == 0);
    cr_assert(p.getAmmoType() == Phaser::ROCKET);

    p.fire();
    cr_assert(p.getCurrentAmmos() == 0);
    p.fire();
    cr_assert_stdout_eq_str("Booooooom\nClip empty, please reload\n");
}


Test(Phaser, test_Phaser_ejectClip)
{  
    Phaser p;

    cr_assert(p.getCurrentAmmos() == 20);
    p.ejectClip();
    cr_assert(p.getCurrentAmmos() == 0);
}

Test(Phaser, test_Phaser_changeType, .init = redirect_all_stdout)
{  
    Phaser p(1, Phaser::ROCKET);

    cr_assert(p.getAmmoType() == Phaser::ROCKET);
    p.changeType(Phaser::PLASMA);
    cr_assert(p.getAmmoType() == Phaser::PLASMA);

    cr_assert_stdout_eq_str("Switching ammo to type: plasma\n");
}

Test(Phaser, test_Phaser_reload, .init = redirect_all_stdout)
{  
    Phaser p(1, Phaser::ROCKET);
    cr_assert(p.getCurrentAmmos() == 1);
    p.reload();
    cr_assert(p.getCurrentAmmos() == 1);
    cr_assert_stdout_eq_str("Reloading...\n");
}

Test(Phaser, test_Phaser_addAmmo_clip_full, .init = redirect_all_stdout)
{  
    Phaser p(1, Phaser::ROCKET);
    p.addAmmo(Phaser::REGULAR);
    cr_assert_stdout_eq_str("Clip full\n");
}

Test(Phaser, test_Phaser_addAmmo, .init = redirect_all_stdout)
{  
    Phaser p(2, Phaser::ROCKET);
    cr_assert(p.getCurrentAmmos() == 2);
    p.fire();
    cr_assert(p.getCurrentAmmos() == 1);
    p.addAmmo(Phaser::REGULAR);
    cr_assert(p.getCurrentAmmos() == 2);

    cr_assert_stdout_eq_str("Booooooom\n");
}

Test(Phaser, test_main, .init = redirect_all_stdout)
{  
    Phaser  p(5, Phaser::ROCKET);

    p.fire();
    p.reload();

    std::cout << "Firing all ammunitions" << std::endl;
    while(p.getCurrentAmmos () > 0)
        p.fire();

    cr_assert_stdout_eq_str("Booooooom\n\
Reloading...\n\
Firing all ammunitions\n\
Booooooom\n\
Booooooom\n\
Booooooom\n\
Booooooom\n\
Booooooom\n");
}

//////////////////////////////////////////////////////////////////////

