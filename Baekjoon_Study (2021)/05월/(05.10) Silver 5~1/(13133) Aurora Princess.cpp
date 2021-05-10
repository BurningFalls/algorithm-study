#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pii> v;
bool dead[501] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N;
	v.push_back({ 0, 0 });
	FOR(i, 1, N) {
		int m, p;
		cin >> m >> p;
		v.push_back({ m, p });
	}
	cin >> M;
	dead[0] = 1;
	FOR(i, 1, M) {
		int num;
		cin >> num;
		dead[num] = 1;
	}
	int ans = 0;
	FOR(i, 1, N) {
		int m, p;
		m = v[i].first;
		p = v[i].second;
		if (dead[i]) continue;
		if (dead[m]) continue;
		if (dead[p]) continue;
		ans++;
	}
	cout << ans;

	return 0;
}