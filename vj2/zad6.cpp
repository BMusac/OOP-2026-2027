#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string ime;
	int JMBAG;
	int god;
	int ECTS;
	double prosjek;
};

void filter_students(Student s[], int n,
				void (*action)(Student&),
				bool (*cond)(const Student&)) {

	for (int i = 0; i < n; i++) {
		if (cond(s[i])) {
			action(s[i]);
		}
	}
}


void ispis(Student& s) {
	cout << s.ime << " " << s.JMBAG << " " << s.god << " " << s.ECTS << " " << s.prosjek << endl;
}

void god(Student& s) {
	s.god++;
}

int main() {
	Student studenti[] = {
		{"Ante", 12345, 1, 30, 4.2},
		{"Pero", 23456, 1, 0, 3.8},
		{"Ivan", 34567, 2, 50, 3.2},
		{"Ana", 45678, 3, 45, 4.5},
		{"Luka", 56789, 1, 20, 3.1}
	};

	int n = 5;
	cout << "Prva godina i jedan ispit: " << endl;
	filter_students(studenti, n, ispis, [](const Student& s) {
		return s.god == 1 && s.ECTS > 0;
		});

	cout << "Prosjek veci od 3.5" << endl;
	filter_students(studenti, n, ispis, [](const Student& s) {
		return s.prosjek > 3.5;
		});

	cout << "Uvecanje god" << endl;

	filter_students(studenti, n, god,
		[](const Student& s) {
			return s.ECTS >= 45;
		});

	for (int i = 0; i < n; i++) {
		ispis(studenti[i]);
	}
}