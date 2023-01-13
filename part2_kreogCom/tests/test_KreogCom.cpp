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