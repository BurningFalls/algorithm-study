#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[200001];

int main() {
	FASTIO;
	int N, C;
	cin >> N >> C;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int left = 1, right = arr[N] - arr[1];
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int start = arr[1];
		FOR(i, 2, N) {
			int dist = arr[i] - start;
			if (dist >= mid) {
				cnt++;
				start = arr[i];
			}
		}
		if (cnt >= C) {
			left = mid + 1;
			ans = mid;
		}
		else if (cnt < C) {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}