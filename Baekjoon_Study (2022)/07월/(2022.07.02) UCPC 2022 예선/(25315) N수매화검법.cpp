#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 2501

struct NODE {
	ll sx;
	ll sy;
	ll ex;
	ll ey;
	ll w;
};

struct POS {
	ll x;
	ll y;
};

int N;
vector<NODE> v(MAX);

int CCW(POS n1, POS n2, POS n3) {
	ll tmp = n1.x * n2.y + n2.x * n3.y + n3.x * n1.y;
	tmp -= n1.y * n2.x + n2.y * n3.x + n3.y * n1.x;
	if (tmp > 0) {
		return 1;
	}
	else if (tmp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

bool is_Cross(NODE n1, NODE n2) {
	POS p1 = { n1.sx, n1.sy };
	POS p2 = { n1.ex, n1.ey };
	POS p3 = { n2.sx, n2.sy };
	POS p4 = { n2.ex, n2.ey };
	return ((CCW(p1, p2, p3) * CCW(p1, p2, p4) <= 0) && (CCW(p3, p4, p1) * CCW(p3, p4, p2) <= 0));
}

int main() {
	FASTIO;
	ll ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> v[i].sx >> v[i].sy >> v[i].ex >> v[i].ey >> v[i].w;
		ans += v[i].w;
	}

	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (i == j) continue;
			if (!is_Cross(v[i], v[j])) continue;
			ans += min(v[i].w, v[j].w);
		}
	}
	cout << ans;

	return 0;
}