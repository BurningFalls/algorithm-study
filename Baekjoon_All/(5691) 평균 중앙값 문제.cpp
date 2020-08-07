#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long int A, B;
	while (true) {
		cin >> A >> B;
		if (A == 0 && B == 0)
			break;
		cout << 2 * A - B << "\n";
	}

	return 0;
}