#include <iostream>
using namespace std;

template <typename T>
inline bool asc(T a, T b) {
	return a < b;
}

template <typename T>
inline bool desc(T a, T b) {
	return a > b;
}

template <typename T>
void my_sort(T *arr, int n, bool(*cmp)(T, T)) {
	T temp;
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
	int arr[] = { 5, 2, 8, 1, 9, 3, 10, 20 };
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
	cout << endl;

	double darr[] = { 5.2, 2.4, 8.3, 1.1, 9.2, 3.6, 10.7, 20.8 };
	my_sort(darr, n, asc);

	for (int i = 0; i < n; i++) {
		cout << darr[i] << " ";
	}

	cout << endl;

	my_sort(darr, n, desc);
	for (int i = 0; i < n; i++) {
		cout << darr[i] << " ";
	}
	cout << endl;

	char carr[] = { 'a', 'c', 'e', 'k', 'b', 'h', 't', 'n' };
	my_sort(carr, n, asc);

	for (int i = 0; i < n; i++) {
		cout << carr[i] << " ";
	}

	cout << endl;

	my_sort(carr, n, desc);
	for (int i = 0; i < n; i++) {
		cout << carr[i] << " ";
	}

}
