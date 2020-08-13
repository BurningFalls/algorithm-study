#include <iostream>
using namespace std;

int main() {
	int N, K;
	int arr[1001] = { 0, };
	int cnt = 0;
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (arr[j] == 0 && j % i == 0) {
				arr[j] = 1;
				cnt++;
			}
			if (cnt == K) {
				cout << j;
				j = N;
				i = N;
			}
		}
	}

	return 0;
}