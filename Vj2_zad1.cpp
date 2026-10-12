#include <iostream>
#include <string>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b));

template<typename T, typename T1, typename T2>
void my_max(T1 a, T2 b) {
	T k = (a > b) ? a : b;
	cout << "Veci je: " << k << endl;
}

inline int my_max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;

	cout << "Prvi: " << a <<endl;
	cout << "Drugi: " << b << endl;
	cout << "Treci: " << c << endl;

	int i = 3;
	cout << my_max(++i, 2) <<endl;
	cout << my_max(++i, 2) << endl;

	my_max<int>(3, 7);
	my_max<double>(2.3, 3.3);
	my_max<char>('A', 'B');
	string pr = "Aaa";
	string dr = "Bbb";
	my_max<string>(pr, dr);
}