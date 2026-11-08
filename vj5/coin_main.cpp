#include <iostream>
#include "Coin.h"

using namespace std;

int main() {

    Coin c1(10);
    Coin c2(20);

    cout << "Broj novcica: " << Coin::remaining() << endl;

    {
        Coin c3(50);

        cout << "Broj novcica: " << Coin::remaining() << endl;
    }

    cout << "Broj novcica: " << Coin::remaining() << endl;

    return 0;
}