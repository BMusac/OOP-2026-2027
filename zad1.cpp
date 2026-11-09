// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class IntStack
{
private:
	int *data;
	int count;
	int cap;
public:
	IntStack(int c = 2): data(new int[c]), count(0), cap(c) {}

	~IntStack() {
		delete[] data;
	}

	IntStack(const IntStack& other) : data(new int[other.cap]), count(other.count), cap(other.cap) {
		for (int i = 0; i < count; i++) {
			data[i] = other.data[i];
		}
	}

	void push(int x) {
		if (count == cap) {
			int* novi = new int[cap * 2];

			for (int i = 0; i < count; i++) {
				novi[i] = data[i];
			}

			delete[] data;

			data = novi;
			cap *= 2;
			
		}
		data[count] = x;
		count++;
		
	}
	int size() const{
		return count;
	}

	int capacity() const{
		return cap;
	}

	int top() const{
		return data[count - 1];
	}
	bool empty() const{
		return count == 0;
	}
	void pop(){
		if (!empty()) {
			count--;
		}
	}
};
// ovdje napisite klasu IntStack

int main()
{
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
	//c.pop();
	c.push(99);
	cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { cout << s.top() << ' '; s.pop(); }
	cout << '\n';
	return 0;
}

/*
Ocekivani ispis:

	5 8 50
	50 99
	50 40 30 20 10
*/
