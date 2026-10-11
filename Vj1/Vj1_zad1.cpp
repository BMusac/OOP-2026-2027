#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "Unesi prvi broj: ";
	cin >> a;
	cout << "Unesi drugi broj: ";
	cin >> b;
	
	cout << "Zbroj brojeva iznosi: " << a + b << endl;
	cout << "Aritmeticka sredina iznosi: " << float(a + b) / 2 << endl;
	bool veci;
	veci = a < b;
	cout << "Bool: " << veci;
}