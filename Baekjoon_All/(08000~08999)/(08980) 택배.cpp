#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

struct BOX {
	int send;
	int receive;
	int cnt;
};

int N, C;
int M;
vector<BOX> v;
int Sum[2001] = { 0, };

bool cmp(BOX a, BOX b) {
	if (a.receive == b.receive) {
		if (a.send == b.send)
			return a.cnt > b.cnt;
		return a.send < b.send;
	}
	return a.receive < b.receive;
}

int main() {
	FASTIO;
	cin >> N >> C;
	cin >> M;
	FOR(i, 1, M) {
		int s, r, c;
		cin >> s >> r >> c;
		v.push_back({ s, r, c });
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	FOR(i, 0, M - 1) {
		int maximum = 0;
		FOR(j, v[i].send, v[i].receive - 1)
			maximum = max(maximum, Sum[j]);
		int possible = min(C - maximum, v[i].cnt);
		ans += possible;
		FOR(j, v[i].send, v[i].receive - 1)
			Sum[j] += possible;
	}
	cout << ans;

	return 0;
}