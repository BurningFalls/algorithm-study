#include <iostream>
using namespace std;

int arr[100001];

int main() {
	int N;
	int max;
	int cnt = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	max = arr[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (max < arr[i]) {
			cnt++;
			max = arr[i];
		}
	}
	cout << cnt;

	return 0;
}