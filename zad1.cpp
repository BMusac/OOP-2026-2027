#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void input_vector(vector<int>& v) {
	int a;
	cout << "Unesite brojeve (0 za kraj): ";
	cin >> a;
	while (a != 0) {
		v.push_back(a);
		cin >> a;
	}
}

int main() {
	vector<int> v;
	input_vector(v);
	int k = 3;
	auto negativan = [](int x) {return x < 0; };
	
	auto c = count_if(v.begin(), v.end(), negativan);
	cout << "Negativnih:" << c <<endl;

	auto djel = find_if(v.begin(), v.end(), [k](int x) {return x % k == 0; });
	cout << "Prvi visekratnik broja " << k <<": " << *djel <<" (pozicija " << djel-v.begin()<<")" <<endl;	

	auto mx = max_element(v.begin(), v.end());
	auto mn = min_element(v.begin(), v.end());
	cout << "min " << *mn << " (pozicija " << mn - v.begin() <<"), max " << *mx <<" (pozicija " << mx - v.begin() <<")"<<endl;

	v.erase(remove_if(v.begin(), v.end(), [k](int x) {return x % k == 0; }),v.end());
	cout << "Bez visekratnika: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}