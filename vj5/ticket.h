
#pragma once
#include <string>

class Ticket {
private:
    std::string concert_name;
    int number;

    static int counter;

public:
    Ticket(const std::string& concert_name);

    static int issued();

    void print() const;
};
