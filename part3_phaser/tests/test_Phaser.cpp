#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "test_include/test_Phaser.hpp"

#include <iostream>

Test(KreogCom, test_KreogCom_ctor)
{  
    Phaser p;

    cr_assert(p.getCurrentAmmos() == 20);
    cr_assert(p.getEmpty() == 0);
    cr_assert(p.getAmmoType() == 1);
}
