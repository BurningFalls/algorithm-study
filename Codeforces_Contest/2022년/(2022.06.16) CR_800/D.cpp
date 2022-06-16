#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 200001

int N;
vector<ll> p(MAX);
vector<vector<ll>> c(MAX, vector<ll>());
vector<pll> lr(MAX);
ll ans;

ll DFS(int node) {
	ll left = lr[node].first;
	ll right = lr[node].second;
	ll add = 0;
	for (int next : c[node]) {
		add += DFS(next);
	}
	if (add < left) {
		ans++;
		return right;
	}
	else if (left <= add && add <= right) {
		return add;
	}
	else if (right < add) {
		return right;
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		ans = 0;
		FOR(i, 1, N) {
			c[i].clear();
		}
		FOR(i, 2, N) {
			cin >> p[i];
			c[p[i]].push_back(i);
		}
		FOR(i, 1, N) {
			cin >> lr[i].first >> lr[i].second;
		}
		DFS(1);
		cout << ans << "\n";
	}

	return 0;
}