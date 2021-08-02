#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll dp[100001];
vector<pii> go[100001];
vector<int> back[100001];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int N, M, K, S, T;
	cin >> N >> M >> K >> S >> T;
	FOR(i, 1, M) {
		int a, b, t;
		cin >> a >> b >> t;
		go[a].push_back({ b, t });
		back[b].push_back(a);
	}
	dp[S] = 0;
	FOR(k, 0, K) {
		FOR(i, 1, N) {
			if (dp[i] == -1) continue;
			for (pii n : go[i]) {
				int goal = n.first;
				int cost = n.second;
				if (goal == 0) continue;
				dp[goal] = max(dp[goal], dp[i] + cost);
			}
		}
		if (k == K) continue;
		FOR(i, 1, N) {
			for (int goal : back[i]) {
				if (goal == 0) continue;
				dp[goal] = max(dp[goal], dp[i]);
			}
		}
	}
	cout << dp[T];


	return 0;
}