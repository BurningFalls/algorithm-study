#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	char x;
	while (true) {
		cin >> num1 >> x >> num2;
		if (num1 == 0 && x == 'W' && num2 == 0)
			break;
		if (x == 'W') {
			if (num1 - num2 < -200)
				cout << "Not allowed\n";
			else
				cout << num1 - num2 << "\n";
		}
		else if (x == 'D')
			cout << num1 + num2 << "\n";
	}

	return 0;
}