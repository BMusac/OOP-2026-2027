#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	int godina;

	cout << "Upisi ime i prezime: ";
	getline(cin, name, ' ');
	cout << "Upisi godinu rodenja: ";
	cin >> godina;

	cout << name;

}