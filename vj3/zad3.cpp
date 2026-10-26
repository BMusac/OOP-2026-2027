#include <iostream>
#include <array>
using namespace std;

constexpr int DAYS = 7;

double total(const array<double, DAYS>& hours) {
	double suma = 0;
	for (int i = 0; i < DAYS; i++) {
		suma += hours[i];
	}

	return suma;
}

int best_day(const array<double, DAYS>& hours) {
	int max = 0;
	for (int i = 1; i < DAYS; i++) {
		if (hours[i] > hours[max]) {
			max = i;
		}
	}

	return max + 1;
}

int main() {
	array<double, DAYS> prvi;

	cout << "Unesi sate: ";
	for (int i = 0; i < DAYS; i++) {
		cin >> prvi[i];
	}

	cout << "Sati ucenja: " << total(prvi) << endl;
	cout << "dan najvise ucenja: " << best_day(prvi) << endl;

	array<double, DAYS> drugi;
	drugi.fill(1.5);

	cout << "prvi == drugi: " << (prvi == drugi) << endl;
	cout << "prvi < drugi: " << (prvi < drugi) << endl;

	prvi.swap(drugi);
	cout << "prvi sati: " << total(prvi) << endl;
	cout << "drugi sati: " << total(drugi) << endl;
}