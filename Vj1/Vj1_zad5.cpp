#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
	double x;
	double y;
};

void move_by(Point* p, double dx, double dy) {
	p->x += dx;
	p->y += dy;
}

double dist(const Point* a, const Point* b) {
	double dx = a->x - b->x;
	double dy = a->y - b->y;
	return sqrt(dx * dx + dy * dy);
}

void move_by(Point& p, double dx, double dy) {
	p.x += dx;
	p.y += dy;
}

double dist(const Point& a, const Point& b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return sqrt(dx * dx + dy * dy);
}

int main() {
	Point p1{5, 6};
	Point p2{2, 4};

	move_by(&p1, 2, 3);
	cout << "Udeljeni su: " << dist(&p1, &p2) << endl;

	move_by(p1, 1, 2);
	cout << "Udaljeni su: " << dist(p1, p2) << endl;

	Point tocke[5] = {
		{1, 4},
		{2,6},
		{1, 3},
		{-2, 2},
		{-1, 0}
	};

	int najblizi = 0;

	for (int i = 1; i < 5; i++) {
		if (dist(tocke[i], Point{ 0,0 }) < dist(tocke[najblizi], Point{ 0,0 })) {
			najblizi = i;
		}
	}

	cout << "Najbliza tocka je " << tocke[najblizi].x << " " << tocke[najblizi].y << endl;
	cout << "Udaljenost od ishodista je: " << dist(tocke[najblizi], Point{ 0,0 }) << endl;
}