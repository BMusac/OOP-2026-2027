#pragma once

class Coin {
private:
    int value;
    static int counter;

public:
    Coin(int value);
    ~Coin();

    static int remaining();
};