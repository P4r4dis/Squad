#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "test_include/test_KreogCom.hpp"

#include <iostream>

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