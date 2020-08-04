#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int arr[10001];

int main() {
	ll N, M;
	ll left, right, mid;
	ll sum;
	ll ans = 0;
	ll cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}
	if (N <= M)
		cout << N;
	else {
		left = 0;
		right = N * 30;
		while (right - left >= 0) {
			mid = (left + right) / 2;
			sum = M;
			for (int i = 1; i <= M; i++)
				sum += mid / arr[i];
			if (sum < N)
				left = mid + 1;
			else if (sum >= N) {
				ans = mid;
				right = mid - 1;
			}
		}
		sum = M;
		for (int i = 1; i <= M; i++)
			sum += (ans - 1) / arr[i];
		for (int i = 1; i <= M; i++) {
			if (ans % arr[i] == 0)
				cnt++;
			if (cnt == N - sum) {
				cout << i;
				break;
			}
		}
	}

	return 0;
}