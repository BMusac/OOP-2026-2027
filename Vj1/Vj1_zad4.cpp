#include<iostream>

using namespace std;

namespace geo {
	const double PI = 3.14;

	double area(double r) {
		return r * r * PI;
	}

	double area(double a, double b) {
		return a * b;
	}

	int area(int a) {
		return a * a;
	}
}

void print_line(char c = '-', int length = 30) {
	for (int i = 0; i < length; i++) {
		cout << c;
	}
	cout << endl;
}

int main() {

	cout << geo::area(5) << endl;
	print_line();
	cout << geo::area(5.0) << endl;
	print_line();
	cout << geo::area(2, 3) << endl;
	print_line();
	cout << geo::area('A') << endl;
	print_line();
}