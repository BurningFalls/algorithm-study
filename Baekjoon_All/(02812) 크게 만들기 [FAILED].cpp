#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	char* arr = new char[N + 1];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j] - '0' == i) {
				arr[j] = 'A';
				cnt++;
				break;
			}
		}
		if (cnt == K) {
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] != 'A') {
			cout << arr[i];
		}
	}

	return 0;
}