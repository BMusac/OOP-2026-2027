#include "Coin.h"

// Definicija statickog clana
int Coin::counter = 0;

// Konstruktor
Coin::Coin(int value) {
    this->value = value;
    counter++;
}

// Destruktor
Coin::~Coin() {
    counter--;
}

// Staticka metoda
int Coin::remaining() {
    return counter;
}