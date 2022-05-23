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
#define INF int(2e9)
#define LINF ll(1e18)

pll Calc(pll x, pll y) {
	if (x.first == 0 && x.second == 0)
		return y;
	if (y.first == 0 && y.second == 0)
		return x;
	return { x.first * y.first, x.second * y.first + x.first * y.second };
}

bool Compare(pll x, pll y) {
	if (x.second * y.first > y.second * x.first)
		return 0;
	else if (x.second * y.first <= y.second * x.first)
		return 1;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pll> C(N);
	FOR(i, 0, N - 1) {
		ll num;
		cin >> num;
		C[i] = { num, 1LL };
	}

	int cnt = 0;
	FOR(i, 1, (1 << N) - 1) {
		pll sum = { 0, 0 };
		FOR(j, 0, N - 1) {
			if (!(i & (1 << j))) continue;
			sum = Calc(sum, C[j]);
		}
		if (Compare({ 100, 99 }, sum) && Compare(sum, { 100, 101 })) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}