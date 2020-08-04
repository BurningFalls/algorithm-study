#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int K, N;
	long long int left, right, mid;
	int answer = 0;
	int sum;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	left = 1;
	right = *max_element(arr, arr + K);
	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < K; i++) {
			sum += (arr[i] / mid);
		}
		if (sum >= N) {
			left = mid + 1;
			answer = mid;
		}
		else if (sum < N) {
			right = mid - 1;
		}
	}
	cout << answer;

	return 0;
}
