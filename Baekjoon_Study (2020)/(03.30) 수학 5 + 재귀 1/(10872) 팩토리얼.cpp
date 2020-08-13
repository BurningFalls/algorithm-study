#include <iostream>
using namespace std;

int fac(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return fac(n - 1) * n;
}

int main() {
	int N;
	cin >> N;
	cout << fac(N) << endl;

	return 0;
}