#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cout << arr[K - 1];

	return 0;
}