#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pii> v;

int main() {
	FASTIO;
	int N, M, S;
	cin >> N >> M >> S;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, x + y });
	}
	v.push_back({ 0, 0 });
	v.push_back({ S, S });
	sort(v.begin(), v.end());
	int ans = -1;
	FOR(i, 0, N) {
		if (v[i + 1].first - v[i].second >= M) {
			ans = v[i].second;
			break;
		}
	}
	cout << ans;


	return 0;
}