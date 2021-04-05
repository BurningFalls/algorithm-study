#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[10001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	int maxi = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	int left = 1, right = maxi;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int tmp = 0;
		FOR(i, 1, N) {
			tmp += arr[i] / mid;
		}
		if (tmp >= K) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}