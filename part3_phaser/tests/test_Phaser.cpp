#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "test_include/test_Phaser.hpp"

#include <iostream>

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