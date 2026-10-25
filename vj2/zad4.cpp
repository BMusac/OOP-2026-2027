#include <iostream>
using namespace std;

void my_transform(int arr[], int n, int(*f)(int)) {
	for (int i = 0; i < n; i++) {
		arr[i] = f(arr[i]);
	}
}

int twice(int a) {
	return a * 2;
}

int main() {
	int arr[] = { 5, 2, 8, 1, 9, 3, 10, 20 };
	int n = 8;

	my_transform(arr, n, twice);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	my_transform(arr, n, [](int x) {
		if (x % 2 == 0) {
			return x / 2;
		}
		else {
			return x * 2;
		}
		});

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int suma = 0;
	int produkt = 1;

	auto sum_prod = [&]() {
		for (int i = 0; i < n; i++) {
			suma += arr[i];
			produkt *= arr[i];
		}
	};

	sum_prod();
	cout << "Suma: " << suma << endl;
	cout << "Produkt: " << produkt << endl;

	int s = 0;
	int prag = 6;
	auto veci_prag = [prag, &s](int arr[], int n) {
		for (int i = 0; i < n; i++) {
			if (arr[i] > prag) {
				s += arr[i];
			}
		}
	};

	veci_prag(arr, n);

	cout << "suma povise praga: " << s;
}