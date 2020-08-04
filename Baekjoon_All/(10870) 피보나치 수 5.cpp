#include <iostream>
using namespace std;

int fib(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	return fib(n - 2) + fib(n - 1);
}

int main() {
	int N;
	cin >> N;
	cout << fib(N) << endl;

	return 0;
}