#include "../test_include/test_KoalaBot.hpp"
#include <iostream>

KoalaBot::KoalaBot( Parts::Arms arms,
                    Parts::Legs legs,
                    Parts::Head head,
                    std::string serial) :
                    _arms(arms),
                    _legs(legs),
                    _head(head),
                    _serial(serial)
{}

KoalaBot::~KoalaBot(void)
{}

std::string     KoalaBot::getSerial(void)
{
    return _serial;
}

void            KoalaBot::setParts(Parts::Arms &arms)
{
    _arms = arms;
}

Parts::Arms     KoalaBot::getArms(void)
{
    return _arms;
}

void            KoalaBot::swapParts(Parts::Arms &arms)
{
    setParts(arms);
}

void            KoalaBot::setParts(Parts::Legs &legs)
{
    _legs = legs;
}

Parts::Legs     KoalaBot::getLegs(void)
{
    return _legs;
}

void            KoalaBot::swapParts(Parts::Legs &legs)
{
    setParts(legs);
}

void            KoalaBot::setParts(Parts::Head &head)
{
    _head = head;
}
Parts::Head     KoalaBot::getHead(void)
{
    return _head;
}

void            KoalaBot::swapParts(Parts::Head &head)
{
    setParts(head);
}