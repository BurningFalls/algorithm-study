#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> X(N);
		vector<int> dp(N);
		map<int, int> mp;
		FOR(i, 0, N - 1) {
			cin >> X[i];
		}
		FOR(i, 0, N - 1) {
			if (!mp.count(X[i])) {
				dp[i] = 1;
			}
			else {
				dp[i] = max(1, dp[mp[X[i]]] - (i - mp[X[i]] - 1) + 1);
			}
			mp[X[i]] = i;
		}

		int maxi = 0;
		FOR(i, 0, N - 1) {
			maxi = max(maxi, dp[i]);
		}
		int start = 0, end = 0, num = 0;
		FOR(i, 0, N - 1) {
			if (dp[i] != maxi) continue;
			num = X[i];
			end = i + 1;
			ROF(j, i, 0) {
				if (X[j] != num) continue;
				if (dp[j] == 1) {
					start = j + 1;
					break;
				}
			}
			break;
		}
		cout << num << " " << start << " " << end << "\n";
	}

	return 0;
}