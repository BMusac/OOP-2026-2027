#include <iostream>

using namespace std;

int main() {
	int a, b, sum;
	float art;
	bool usporedba;

	cout << "Upisi prvi broj: ";
	cin >> a;
	cout << "Upisi drugi broj: ";
	cin >> b;

	sum = a + b;

	art = float(sum) / 2.0;

	usporedba = a < b;

	cout << "Suma brojeva iznosi: " << sum <<endl;
	cout << "Aritmeticka sredina je: " << art << endl;
	cout << "Usporedba je: " << usporedba <<endl;
}