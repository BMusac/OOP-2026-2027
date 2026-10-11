#include <iostream>
using namespace std;

struct Fraction
{
	int n;
	int d;

	void reduce() {
		int djel;
		int veci;
		if (n > d) {
			veci = n;
		}
		else {
			veci = d;
		}
		for (int i = veci; i > 0; i--) {
			if (d % i == 0 && n % i == 0) {
				djel = i;
				break;
			}
		}
		n = n / djel;
		d = d / djel;
	}

	double value() {
		return double(n) / double(d);
	}

	void print() {
		cout << int(n) << "/" << int(d) << endl;
	}

};


Fraction sum(const Fraction& a, const Fraction& b) {
	int denum = a.d * b.d;
	int numer = a.n * b.d + b.n * a.d;

	Fraction suma{ numer, denum };
	suma.reduce();

	return suma;

}

int main() {
	Fraction f1{3, 6};
	Fraction f2{1, 4};
	f1.print();
	double djeljenje  = f1.value();
	cout << "Djeljenje je: " << djeljenje << endl;
	f1.reduce();
	f1.print();

	Fraction zbrajanje = sum(f1, f2);
	cout << "Zbrajanje je: ";
	zbrajanje.print();
}