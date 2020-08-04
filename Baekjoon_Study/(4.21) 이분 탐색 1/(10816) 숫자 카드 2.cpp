#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, M;
	int num;
	int left, right, mid;
	int lower_bound, upper_bound;
	// lower_bound : k값 이상이 처음 발견되는 위치
	// upper_bound : k값을 초과하는 값이 처음 발견되는 위치
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;

		left = 0;
		right = N;
		while (left < right) {
			mid = (left + right) / 2;
			if (num <= arr[mid]) {
				right = mid;
			}
			else if (num > arr[mid]) {
				left = mid + 1;
			}
		}
		lower_bound = right + 1;

		left = 0;
		right = N;
		while (left < right) {
			mid = (left + right) / 2;
			if (num < arr[mid]) {
				right = mid;
			}
			else if (num >= arr[mid]) {
				left = mid + 1;
			}
		}
		upper_bound = right + 1;

		cout << upper_bound - lower_bound << " ";
	}

	return 0;
}