#include <iostream>
using namespace std;

int main() {
	int a1, a2, a3;
	while (true) {
		cin >> a1 >> a2 >> a3;
		if (a1 == 0 && a2 == 0 && a3 == 0)
			break;
		if (a3 - a2 == a2 - a1) {
			cout << "AP ";
			cout << a3 + (a2 - a1) << "\n";
		}
		else if (a3 / a2 == a2 / a1) {
			cout << "GP ";
			cout << a3 * (a2 / a1) << "\n";
		}
	}

	return 0;
}