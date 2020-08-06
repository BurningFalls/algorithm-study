#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[1001];
	long long int file_size;
	long long int ans = 0;
	long long int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> file_size;
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0) continue;
		if (arr[i] % file_size == 0)
			temp = arr[i] / file_size;
		else
			temp = arr[i] / file_size + 1;
		ans += temp * file_size;
	}
	cout << ans;

	return 0;
}