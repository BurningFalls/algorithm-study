#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[5];
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++) {
		if (arr[i] % 10 == N) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}