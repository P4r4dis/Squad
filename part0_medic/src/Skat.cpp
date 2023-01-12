#include "../include/Skat.hpp"
#include <iostream>

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

void                    Skat::shareStimPaks(int number, int &stock)
{
    if(number >= _stimPaks)
        std::cout << "Don't be greedy" << std::endl;
    else
    {
        stock += number;
        _stimPaks -= number;
        std::cout << "Keep the change." << std::endl;
    }
}