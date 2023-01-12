#include "../include/Parts.hpp"
#include <iostream>

Parts::Arms::Arms(std::string serial, bool functional)  :   _serial(serial),
                                                            _functional(functional)
{}

Parts::Arms::~Arms(void)
{}

bool            Parts::Arms::isFunctional(void) const
{
    return _functional;
}

std::string     Parts::Arms::serial(void) const
{
    return _serial;
}