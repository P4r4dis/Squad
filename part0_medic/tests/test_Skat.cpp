#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "test_include/test_Skat.hpp"
#include <iostream>

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

Test(Skat, test_addStimPaks_zero, .init=redirect_all_stdout)
{
    Skat    skat;

    skat.addStimPaks(0);
    cr_assert(skat.getStimPaks() == 15);
    cr_assert_stdout_eq_str("Hey boya, did you forget something?\n");
}

Test(Skat, test_addStimPaks)
{
    Skat    skat;

    skat.addStimPaks(10);
    cr_assert(skat.getStimPaks() == 25);
}

Test(Skat, test_useStimPaks_zero, .init=redirect_all_stdout)
{
    Skat    skat;

    cr_assert(skat.stimPaks() == 15);
    skat.stimPaks() = 0;
    cr_assert(skat.stimPaks() == 0);

    skat.useStimPaks();
    cr_assert_stdout_eq_str("Mediiiiiic\n");
}

Test(Skat, test_useStimPaks, .init=redirect_all_stdout)
{
    Skat    skat;

    cr_assert(skat.stimPaks() == 15);
    skat.useStimPaks();
    cr_assert(skat.stimPaks() == 14);
    cr_assert_stdout_eq_str("Time to kick some ass and chew bubble gum.\n");
}

Test(Skat, test_status, .init=redirect_all_stdout)
{
    Skat    skat;
    
    skat.status();
    cr_assert_stdout_eq_str("Soldier bob reporting 15 stimpaks remaining sir!\n");
}

Test(Skat, test_skat_main, .init=redirect_all_stdout)
{
    Skat    s("Junior", 5);
    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();
    cr_assert_stdout_eq_str("Soldier Junior\n\
Soldier Junior reporting 5 stimpaks remaining sir!\n\
Time to kick some ass and chew bubble gum.\n");
}