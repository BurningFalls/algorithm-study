#include <iostream>
using namespace std;

int main() {
	int N, K;
	int num[21];
	int ans[21];
	char temp;
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		cin >> num[i];
		ans[i] = num[i];
		cin >> temp;
	}
	cin >> num[N - 1];
	ans[N - 1] = num[N - 1];
	for (int t = 0; t < K; t++) {
		for (int i = 0; i < N - 1 - t; i++) {
			ans[i] = num[i + 1] - num[i];
		}
		for (int i = 0; i < N - 1 - t; i++) {
			num[i] = ans[i];
		}
	}
	for (int i = 0; i < N - K; i++) {
		cout << ans[i];
		if (i != N - K - 1)
			cout << ",";
	}

	return 0;
}