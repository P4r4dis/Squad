#include "../include/Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks) :     _name(name),
                                                        _stimPaks(stimPaks)
{}

Skat::~Skat()
{}

const std::string&      Skat::getName(void)
{
    return _name;
}

int                     Skat::getStimPaks(void)
{
    return _stimPaks;
}

int&                    Skat::stimPaks(void)
{
    return _stimPaks;
}