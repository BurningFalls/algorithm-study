#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	double x1, y1, r1, x2, y2, r2;
	double d;
	for (int a = 0; a < T; a++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		else {
			d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			if (d > r1 + r2 || d < abs(r1 - r2)) {
				cout << 0 << endl;
			}
			else if (d == r1 + r2 || d == abs(r1 - r2)) {
				cout << 1 << endl;
			}
			else if (d < r1 + r2 && d > abs(r1 - r2)) {
				cout << 2 << endl;
			}
		}
	}

	return 0;
}