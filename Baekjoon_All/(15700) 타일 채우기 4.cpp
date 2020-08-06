#include <iostream>
using namespace std;

int main() {
	long long int N, M;
	cin >> N >> M;
	if (N % 2 == 0 && M % 2 == 0) {
		cout << (N / 2) * (M / 2) * 2;
	}
	else if (N % 2 == 0 && M % 2 == 1) {
		cout << (N / 2) * (M / 2) * 2 + N / 2;
	}
	else if (N % 2 == 1 && M % 2 == 0) {
		cout << (N / 2) * (M / 2) * 2 + M / 2;
	}
	else if (N % 2 == 1 && M % 2 == 1) {
		cout << (N / 2) * (M / 2) * 2 + N / 2 + M / 2;
	}

	return 0;
}