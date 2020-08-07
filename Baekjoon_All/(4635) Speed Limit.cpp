#include <iostream>
using namespace std;

int main() {
	int N;
	int s[11], t[11];
	int sum;
	while (true) {
		sum = 0;
		cin >> N;
		if (N == -1)
			break;
		for (int i = 0; i < N; i++) {
			cin >> s[i] >> t[i];
		}
		sum += s[0] * t[0];
		for (int i = 1; i < N; i++) {
			sum += s[i] * (t[i] - t[i - 1]);
		}
		cout << sum << " miles\n";
	}

	return 0;
}