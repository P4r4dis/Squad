#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "test_include/test_KoalaBot.hpp"
#include "test_include/test_Parts.hpp"

#include <iostream>

Test(Parts_Arms, test_Arms_ctor)
{  
    Parts::Arms     arms;

    cr_assert(arms.isFunctional() == true);
    cr_assert(arms.serial() == "A-01");
}
