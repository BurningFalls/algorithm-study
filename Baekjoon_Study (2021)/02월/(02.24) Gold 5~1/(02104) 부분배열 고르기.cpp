#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
ll arr[100001];
ll sum[100001];

ll Solve(int start, int end) {
	if (start == end)
		return arr[start] * arr[start];
	int mid = (start + end) / 2;
	ll ret = max(Solve(start, mid), Solve(mid + 1, end));

	int left = mid;
	int right = mid + 1;
	ll minimum = min(arr[left], arr[right]);
	ret = max(ret, (sum[right] - sum[left - 1]) * minimum);

	while (start < left || right < end) {
		if (right < end && (start == left || arr[left - 1] < arr[right + 1])) {
			right += 1;
			minimum = min(minimum, arr[right]);
		}
		else {
			left -= 1;
			minimum = min(minimum, arr[left]);
		}
		ret = max(ret, (sum[right] - sum[left - 1]) * minimum);
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> N;
	sum[0] = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cout << Solve(1, N);

	return 0;
}