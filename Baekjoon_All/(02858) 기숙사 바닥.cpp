#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int R, B;
	int X, Y;
	cin >> R >> B;
	for (int i = 1; i <= (B + R); i++) {
		if ((B + R) % i == 0) {
			X = i;
			Y = (B + R) / i;
			if (2 * (X + Y) - 4 == R) {
				cout << max(X, Y) << " " << min(X, Y) << endl;
				break;
			}
		}
	}


	return 0;
}