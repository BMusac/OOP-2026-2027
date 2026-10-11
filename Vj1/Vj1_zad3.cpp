#include <iostream>
#include <math.h>
using namespace std;

int& find_max(int arr[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[max] < arr[i]){
			max = i;
		}
	}
	return arr[max];
}

int main() {
	int numbers[] = { 4, -7, 12, 0, 9, -3 };
	int n = sizeof(numbers) / sizeof(numbers[0]);
	for (int& i : numbers) {
		if (i < 0) {
			i = abs(i);
		}
		cout << i << " ";
	}
	cout << endl;

	find_max(numbers, n) = 0;
	for (int j : numbers) {
		cout << j << " ";
	}
}