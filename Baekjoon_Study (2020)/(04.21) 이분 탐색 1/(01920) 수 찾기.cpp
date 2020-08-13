#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, M;
	int num;
	int left, right, mid;
	bool flag = false;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		flag = false;
		left = 0;
		right = N - 1;
		cin >> num;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num == arr[mid]) {
				flag = true;
				break;
			}
			else if (num < arr[mid]) {
				right = mid - 1;
			}
			else if (num > arr[mid]) {
				left = mid + 1;
			}
		}
		if (flag)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}