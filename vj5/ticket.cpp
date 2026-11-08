
#include <iostream>
#include "Ticket.h"

int Ticket::counter = 0;

Ticket::Ticket(const std::string& concert_name)
    : concert_name(concert_name)
{
    counter++;
    number = counter;
}

int Ticket::issued()
{
    return counter;
}

void Ticket::print() const
{
    std::cout << concert_name << " - ulaznica broj "
        << number << std::endl;
}
