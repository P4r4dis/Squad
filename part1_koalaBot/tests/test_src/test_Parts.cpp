#include "../test_include/test_Parts.hpp"
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

void            Parts::Arms::informations(void) const
{
    std::cout   << "\t[Parts] Arms " << _serial << " status : " 
                << (_functional ? "OK" : "KO") << std::endl; 
}

/// LEGS ////////////////////////////////////////////////////
Parts::Legs::Legs(std::string serial, bool functional)  :   _serial(serial),
                                                            _functional(functional)
{}

Parts::Legs::~Legs(void)
{}

bool            Parts::Legs::isFunctional(void) const
{
    return _functional;
}

std::string     Parts::Legs::serial(void) const
{
    return _serial;
}

void            Parts::Legs::informations(void) const
{
    std::cout   << "\t[Parts] Legs " << _serial << " status : " 
                << (_functional ? "OK" : "KO") << std::endl; 
}