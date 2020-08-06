#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[100001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int cnt = 1;
	long long int ans;
	int max_cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			cnt++;
		}
		else {
			if (max_cnt < cnt) {
				max_cnt = cnt;
				ans = arr[i];
			}
			cnt = 1;
		}
	}
	if (max_cnt < cnt) {
		max_cnt = cnt;
		ans = arr[N - 1];
	}
	cout << ans;

	return 0;
}