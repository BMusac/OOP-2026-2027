#include <iostream>
#include <string>
using namespace std;

int main() {
	string ime;
	int godina;
	int brojac = 0;
	cout << "Unesi god. rodenja: ";
	cin >> godina;

	cin.ignore();

	cout << "Unesi ime i prezime: ";
	getline(cin, ime);

	for (int i = 0; i < ime.length(); i++) {
		if (i == 0) {
			cout << ime[i] << ".";
		}
		if (ime[i] == ' ') {
			cout << ime[i + 1] << endl;
		}
	}

	for (char slovo : ime) {
		if (slovo != ' ') {
			brojac++;
		}
	}

	cout << "Duzina imena i prezimena bez razmaka iznosi: " << brojac << endl;
	cout << "Godine koje navrsava ove godine iznosi: " << 2026 - godina << endl;

	

}