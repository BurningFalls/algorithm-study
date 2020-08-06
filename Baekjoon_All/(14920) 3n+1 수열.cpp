#include <iostream>
using namespace std;

int main() {
	int N;
	int cnt = 1;
	cin >> N;
	while (N != 1) {
		cnt++;
		if (N % 2 == 0) {
			N /= 2;
		}
		else {
			N = 3 * N + 1;
		}
	}
	cout << cnt;

	return 0;
}