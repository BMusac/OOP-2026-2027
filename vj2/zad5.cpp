#include <iostream>
using namespace std;

inline double add(double a, double b) {
    return a + b;
}

inline double subtract(double a, double b) {
    return a - b;
}

inline double multiply(double a, double b) {
    return a * b;
}

inline double divide(double a, double b) {
    return a / b;
}

int main() {
    double(*operacije[])(double, double) = { add, subtract, multiply, divide };
    double a, b;
    int c;
    cout << "Upisi prvi broj: ";
    cin >> a;
    cout << "Unesi drugi broj: ";
    cin >> b;
    cout << "Unesi operaciju: ";
    cin >> c;

    if (b == 0) {
        cout << "Zabranjeno djelit s 0";
    }
    else {
        cout << "Rez je: " << operacije[c](a, b);
    }
}