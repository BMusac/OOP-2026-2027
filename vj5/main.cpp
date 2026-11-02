#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void ispisi(vector<string>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " " << endl;
	}
}

void proces(vector<string>& v) {
	auto mn = min_element(v.begin(), v.end());
	string min = *mn;
	cout << min;
	auto kraj = remove(v.begin(), v.end(), min);
	v.erase(kraj, v.end());
}

int main() {
	vector<string> v1 = { "abc", "a", "b", "b", "a" };
	ispisi(v1);
	cout << "----" << endl;
	proces(v1);
	cout << endl;
	cout << "----" << endl;

	ispisi(v1);
}