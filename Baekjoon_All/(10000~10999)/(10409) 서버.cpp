#include <iostream>
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	int* arr = new int[N + 1];
	int sum = 0;
	int max = N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		sum += arr[i];
		if (sum > T) {
			max = i - 1;
			break;
		}
	}
	cout << max;

	return 0;
}