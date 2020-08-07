#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		if (b % a == 0) {
			cout << "factor";
		}
		else if (a % b == 0) {
			cout << "multiple";
		}
		else {
			cout << "neither";
		}
		cout << endl;
	}

	return 0;
}