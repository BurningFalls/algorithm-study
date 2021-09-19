#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<ll, ll>
#define LEN(s) int(s.size())
#define INF 987654321

int N, M;
int W[101], V[101];
int Bag[101];
int dp[1000001];
vector<pair<pii, int>> v;

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.second * b.first.first == b.first.second * a.first.first)
		return a.second < b.second;
	return a.first.second * b.first.first > b.first.second * a.first.first;
}

int main() {
	FASTIO;
	MEMSET(dp, -1);
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> W[i] >> V[i];
	int maxi_bag = 0;
	FOR(i, 1, M) {
		cin >> Bag[i];
		maxi_bag = max(maxi_bag, Bag[i]);
	}
	dp[0] = 0;
	FOR(i, 1, N) {
		ROF(j, maxi_bag, W[i]) {
			if (dp[j - W[i]] == -1) continue;
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
		}
	}
	FOR(i, 1, maxi_bag) {
		dp[i] = max(dp[i], dp[i - 1]);
	}
	FOR(i, 1, M) {
		if (dp[Bag[i]] == -1) continue;
		v.push_back({ { Bag[i], dp[Bag[i]] }, i });
	}
	sort(v.begin(), v.end(), cmp);
	if (!v.empty())
		cout << v[0].second;

	return 0;
}