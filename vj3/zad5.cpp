#include <iostream>
#include <string>
using namespace std;

string with_separators(string digits) {
    int pocetak = 0;

    if (digits[0] == '-') {
        pocetak = 1;
    }

    for (int i = digits.size() - 3; i > pocetak; i -= 3) {
        digits.insert(i, ".");
    }

    return digits;
}

string without_separators(string text) {
    int pozicija = text.find('.');

    while (pozicija != string::npos) {
        text.erase(pozicija, 1);
        pozicija = text.find('.');
    }

    return text;
}

int main() {
    string broj;

    cout << "Unesi broj: ";
    cin >> broj;

    cout << "S tockama: " << with_separators(broj) << endl;
    cout << "Bez tocaka: " << without_separators(broj) << endl;

    return 0;
}