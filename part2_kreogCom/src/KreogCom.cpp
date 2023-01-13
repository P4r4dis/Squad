#include "../include/KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial) :  _x(x), _y(y),
                                                m_serial(serial),
                                                _next(nullptr)
{
    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom(void)
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

int     KreogCom::getSerial(void) const
{
    return m_serial;
}

int     KreogCom::getX(void)
{
    return _x;
}

int     KreogCom::getY(void)
{
    return _y;
}

void        KreogCom::addCom(int x, int y, int serial)
{
    // Create a new KreogCom with the given x, y, and serial values
    KreogCom    *newKreogCom = new KreogCom(x, y, serial);

    // Get the current next KreogCom
    KreogCom    *oldKreogCom = getCom();

    // If there is already a next KreogCom
    if (oldKreogCom != nullptr) {
        // Link the new KreogCom to the old one
        newKreogCom->_next = oldKreogCom;
    }
    // Link the new KreogCom to the current one
    _next = newKreogCom;
}

KreogCom    *KreogCom::getCom(void)
{
    return _next;
}


void        KreogCom::removeCom() {
    if (_next != nullptr) {
        // Create a pointer to the next KreogCom in the list
        KreogCom* temp = _next;
        // Update the current KreogCom's next pointer to the next next KreogCom
        _next = _next->_next;
        // Set the next pointer of the deleted object to nullptr to avoid any dangling pointers
        temp->_next = nullptr;
        // Delete the next KreogCom
        delete temp;
    }
}

void        KreogCom::ping(void) const
{
    std::cout   << "KreogCom " << m_serial << " currently at "
                << _x << " " << _y << std::endl;
}

void        KreogCom::locateSquad(void) const
{
    KreogCom    *current = _next;
    
    // Print information about all linked KreogCom
    while (current != nullptr) {
        current->ping();
        if(current->_next)
            current = current->_next;
        else
            break;
    }
    // Print information about the current KreogCom
    ping();
}