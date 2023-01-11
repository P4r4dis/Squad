#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "test_include/test_Skat.hpp"

Test(Skat, test_skat_construction)
{
    Skat    skat;

    cr_assert(skat.getName() == "bob");
    cr_assert(skat.getStimPaks() == 15);

    Skat    skat2("SKAT", 50);
    cr_assert(skat2.getName() == "SKAT");
    cr_assert(skat2.getStimPaks() == 50);   
}

Test(Skat, test_stimPaks)
{
    Skat    skat;

    cr_assert(skat.getName() == "bob");
    cr_assert(skat.getStimPaks() == 15);

    Skat    skat2("SKAT", 50);
    cr_assert(skat2.getName() == "SKAT");
    cr_assert(skat2.getStimPaks() == 50);

    skat2.stimPaks() = 5;
    cr_assert(skat2.stimPaks() == 5);
    cr_assert(skat2.getStimPaks() == 5);
}

Test(Skat, test_name)
{
    Skat    skat;

    cr_assert(skat.name() == "bob");
}