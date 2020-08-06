#include <iostream>
using namespace std;

int main() {
	int T;
	int a, b, c, d;
	cin >> T;
	int arr[8];
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[j];
		}
		a = arr[0] + arr[4];
		if (a < 1)
			a = 1;
		b = arr[1] + arr[5];
		if (b < 1)
			b = 1;
		c = arr[2] + arr[6];
		if (c < 0)
			c = 0;
		d = arr[3] + arr[7];

		cout << a + 5 * b + 2 * c + 2 * d << "\n";
	}

	return 0;
}