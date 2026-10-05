#include <iostream>
using namespace std;

int& find_max(int arr[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {

	}
}

int main() {
	int numbers[] = { 4, -7, 12, 0, 9, -3 };
	for (int i : numbers) {
		if (i < 0) {
			cout << abs(i) << endl;
		}
		else {
			cout << i << endl;
		}
	}
}