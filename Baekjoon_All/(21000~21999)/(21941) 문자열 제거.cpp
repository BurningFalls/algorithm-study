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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	string S;
	int M;
	cin >> S;
	cin >> M;
	int len = LEN(S);
	vector<int> dp(len + 1, 0);
	map<string, int> mp;
	FOR(i, 1, M) {
		string A;
		int X;
		cin >> A >> X;
		if (X <= LEN(A)) continue;
		mp[A] = X;
	}

	ROF(i, len - 1, 0) {
		string sub_str = "";
		dp[i] = dp[i + 1] + 1;
		FOR(j, i, len - 1) {
			sub_str += S[j];
			if (mp.count(sub_str)) {
				dp[i] = max(dp[i], dp[j + 1] + mp[sub_str]);
			}
		}
	}

	cout << dp[0];

	return 0;
}