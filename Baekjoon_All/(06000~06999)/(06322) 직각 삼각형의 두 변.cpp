#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool Check(double a, double b, double& c) {
	bool flag = false;
	// 力老 奴 荐 = c
	c = sqrt(a * a + b * b);
	if (a + b > c)
		flag = true;
	// 力老 奴 荐 = a or b
	if (a > b) {
		c = sqrt(a * a - b * b);
		if (b + c > a)
			flag = true;
	}
	else if (a <= b) {
		c = sqrt(b * b - a * a);
		if (a + c > b)
			flag = true;
	}
	return flag;
}

int main() {
	double a, b, c;
	int cs = 1;
	cout << fixed << setprecision(3);
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		cout << "Triangle #" << cs << "\n";
		if (a == -1) {
			a = sqrt(c * c - b * b);
			if (a + b > c)
				cout << "a = " << a << "\n";
			else
				cout << "Impossible.\n";
		}
		else if (b == -1) {
			b = sqrt(c * c - a * a);
			if (a + b > c)
				cout << "b = " << b << "\n";
			else
				cout << "Impossible.\n";
		}
		else if (c == -1) {
			c = sqrt(a * a + b * b);
			if (a + b > c)
				cout << "c = " << c << "\n";
			else
				cout << "Impossible.\n";
		}
		cs++;
		cout << "\n";
	}

	return 0;
}