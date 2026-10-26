#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector < int > &v) {
	int a;
	cout << "Unesi broj za vektor: ";
	cin >> a;
	while (a != 0) {
		v.push_back(a);
		cin >> a;
	}

}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> a;
	input_vector(a);
	print_vector(a);

	for (auto i = a.rbegin(); i != a.rend(); i++) {
		cout << *i << " ";
	}

	cout << endl;

	vector<int> b;
	for (int i = 1; i <= 20; i++) {
		b.push_back(i);
		cout << "size: " << b.size() << " capac: " << b.capacity() << endl;
	}

	vector<int> c;
	c.reserve(100);
	for (int i = 1; i <= 20; i++) {
		c.push_back(i);
		cout << "size: " << c.size() << " capac: " << c.capacity() << endl;
	}

	c.shrink_to_fit();
	cout << c.capacity();

}