#include <iostream>
using namespace std;

int main() {
	int N;
	int a, b, c;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		cout << "Scenario #" << i << ":\n";
		if (a >= b && a >= c) {
			if (a * a == b * b + c * c)
				cout << "yes\n\n";
			else
				cout << "no\n\n";
		}
		else if (b >= a && b >= c) {
			if (b * b == a * a + c * c)
				cout << "yes\n\n";
			else
				cout << "no\n\n";
		}
		else if (c >= a && c >= b) {
			if (c * c == a * a + b * b)
				cout << "yes\n\n";
			else
				cout << "no\n\n";
		}
	}

	return 0;
}