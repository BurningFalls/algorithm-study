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
#define INF 2e9
#define LINF 1e18

pll arr[501];
set<pll> s;

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i].first >> arr[i].second;
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (i == j) continue;
			ll dy = arr[j].first - arr[i].first;
			ll dx = arr[j].second - arr[i].second;
			bool yflag = false, xflag = false;
			if (dy < 0) {
				dy *= (-1);
				yflag = true;
			}
			if (dx < 0) {
				dx *= (-1);
				xflag = true;
			}
			ll gcd = Gcd(dy, dx);
			dy /= gcd;
			dx /= gcd;
			if (yflag) {
				dy *= (-1);
			}
			if (xflag) {
				dx *= (-1);
			}
			s.insert({ dy, dx });
		}
	}
	cout << LEN(s);


	return 0;
}