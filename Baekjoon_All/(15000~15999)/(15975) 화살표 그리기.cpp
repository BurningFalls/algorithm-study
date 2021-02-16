#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
vector<int> v[100001];

int main() {
	FASTIO;
	int x, y;
	ll ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> x >> y;
		v[y].push_back(x);
	}
	FOR(i, 1, N) {
		sort(v[i].begin(), v[i].end());
	}
	FOR(i, 1, N) {
		int len = v[i].size();
		if (len <= 1) continue;
		ans += v[i][1] - v[i][0];
		ans += v[i][len - 1] - v[i][len - 2];
		FOR(j, 1, len - 2) {
			ans += min(v[i][j] - v[i][j - 1], v[i][j + 1] - v[i][j]);
		}
	}
	cout << ans;

	return 0;
}