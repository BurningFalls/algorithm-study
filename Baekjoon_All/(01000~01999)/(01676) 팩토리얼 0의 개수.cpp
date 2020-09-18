#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N >= 0 && N <= 24) {
		cout << N / 5;
	}
	else if (N >= 25 && N <= 124) {
		cout << N / 5 + N / 25;
	}
	else if (N >= 125 && N <= 500) {
		cout << N / 5 + N / 25 + N / 125;
	}

	return 0;
}