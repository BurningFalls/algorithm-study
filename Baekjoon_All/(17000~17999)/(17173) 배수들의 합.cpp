#include <iostream>
using namespace std;

int main() {
	int N, M;
	bool check[1001] = { 0, };
	int arr[1001];
	int sum = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 1; arr[i] * j <= N; j++) {
			check[arr[i] * j] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == 1) {
			sum += i;
		}
	}
	cout << sum;

	return 0;
}