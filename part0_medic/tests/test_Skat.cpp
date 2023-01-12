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

Test(Skat, test_shareStimPaks, .init=redirect_all_stdout)
{
    Skat    skat;
    Skat    skat2("SKAT", 50);

    cr_assert(skat2.getStimPaks() == 50);
    skat.shareStimPaks(10, skat2.stimPaks());
    cr_assert(skat2.stimPaks() == 60);
    cr_assert(skat.stimPaks() == 5);
    cr_assert_stdout_eq_str("Keep the change.\n");
}

Test(Skat, test_shareStimPaks_greedy, .init=redirect_all_stdout)
{
    Skat    skat;
    Skat    skat2("SKAT", 50);

    cr_assert(skat2.getStimPaks() == 50);
    skat.shareStimPaks(20, skat2.stimPaks());
    cr_assert(skat2.stimPaks() == 50);
    cr_assert(skat.stimPaks() == 15);
    cr_assert_stdout_eq_str("Don't be greedy\n");
}