#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cout << "Unesi broj dana: ";
	cin >> n;

	vector<double> temp(n);

	for (int i = 0; i < temp.size(); i++) {
		cin >> temp[i];
	}

	vector<double> promjena;
	promjena.reserve(n - 1);

	vector<double>::iterator a = temp.begin() + 1;
	vector<double>::iterator b = temp.begin();

	while (a != temp.end()) {
		promjena.push_back(*a - *b);
		a++;
		b++;
	}

	for (int i = 0; i < promjena.size(); i++) {
		cout << promjena[i] << " ";
	}

	cout << endl;

	if (temp.size() < 7) {
		double zadnja = temp[temp.size() - 1];
		temp.resize(7, zadnja);
	}
	else {
		temp.resize(7);
	}

	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " ";
	}

	cout << endl;

	vector<int> c(5);
	vector<int> d{5};

	cout << "Broj elemenata u a: " << c.size() << endl;
	cout << "Broj elemenata u b: " << d.size() << endl;

}