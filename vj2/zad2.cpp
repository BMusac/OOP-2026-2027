#include <iostream>
using namespace std;

inline bool asc(int a, int b) {
	return a < b;
}

inline bool desc(int a, int b) {
	return a > b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int)) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (!cmp(arr[j], arr[j + 1])) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int arr[] = { 5, 2, 8, 1, 9, 3, 10, 20};
	int n = 8;

	my_sort(arr, n, asc);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	my_sort(arr, n, desc);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}