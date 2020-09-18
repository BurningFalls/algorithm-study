#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, K;
	int maximum = 0;
	int minimum;
	cin >> N >> M >> K;
	for (int i = 0; i <= K; i++) {
		minimum = min((N - i) / 2, M - (K - i));
		maximum = max(maximum, minimum);
	}
	cout << maximum;

	return 0;
}