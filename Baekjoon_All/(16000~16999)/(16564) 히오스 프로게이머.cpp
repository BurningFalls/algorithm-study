#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<int> X(N);
	int mini = INF;
	int maxi = 0;
	FOR(i, 0, N - 1) {
		cin >> X[i];
		mini = min(mini, X[i]);
		maxi = max(maxi, X[i]);
	}
	int left = mini, right = maxi + K;
	int ans = mini;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll sum = 0;
		FOR(i, 0, N - 1) {
			sum += max(0, mid - X[i]);
		}
		if (sum <= K) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else if (sum > K) {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}