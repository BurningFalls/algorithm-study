#include <iostream>
using namespace std;

int main() {
	int a, b;
	int temp;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		temp = a / b;
		cout << temp << " " << a - temp * b << " / " << b << "\n";
	}

	return 0;
}