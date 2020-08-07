#include <iostream>
using namespace std;

int main() {
	int N, K;
	int cnt = 0;
	int answer = 0;
	cin >> N >> K;
	for (int i = N; i >= 1; i--) {
		if (N % i == 0) {
			cnt++;
			if (cnt == K) {
				answer = N / i;
				break;
			}
		}
	}
	cout << answer;

	return 0;
}