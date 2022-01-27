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
#define INF 2e9
#define LINF 1e18

struct NODE {
	int r;
	int b;
	int d;
};

vector<vector<int>> dp(5001, vector<int>(5001, -1));

bool compare(NODE a, NODE b) {
	if (a.r == b.r)
		return a.b < b.b;
	return a.r < b.r;
}

bool compare2(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	int rsum = 0, bsum = 0;
	vector<NODE> v(M);
	dp[0][0] = 0;
	FOR(i, 0, M - 1) {
		cin >> v[i].r >> v[i].b >> v[i].d;
	}
	sort(ALL(v), compare);
	FOR(i, 0, M - 1) {
		int r = v[i].r;
		int b = v[i].b;
		int d = v[i].d;
		rsum += r;
		bsum += b;
		ROF(i, rsum, r) {
			ROF(j, bsum, b) {
				if (dp[i - r][j - b] == -1) continue;
				dp[i][j] = max(dp[i][j], dp[i - r][j - b] + d);
			}
		}
	}
	vector<pii> ans;
	FOR(idx, 1, N) {
		int r, b;
		cin >> r >> b;
		ans.push_back({ idx, max(0, dp[r][b]) });
	}
	sort(ALL(ans), compare2);
	for (pii x : ans) {
		cout << x.first << " " << x.second << "\n";
	}


	return 0;
}