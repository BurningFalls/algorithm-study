#include <iostream>
using namespace std;

int main() {
	int T;
	int A, B, C;
	cin >> T;
	A = T / 300;
	T -= A * 300;
	B = T / 60;
	T -= B * 60;
	if (T % 10 != 0)
		cout << -1;
	else {
		C = T / 10;
		cout << A << " " << B << " " << C;
	}

	return 0;
}