#include "../include/Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks) :     _name(name),
                                                        _stimPaks(stimPaks)
{}

Skat::~Skat()
{}

int&                    Skat::stimPaks(void)
{
    return _stimPaks;
}

const std::string       &Skat::name(void)
{
    return _name;
}