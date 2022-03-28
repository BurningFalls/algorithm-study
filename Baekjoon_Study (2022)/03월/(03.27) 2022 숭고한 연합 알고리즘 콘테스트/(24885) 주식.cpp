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

ll N, M, K;
vector<ll> P(11);
ll ans = 0;

void DFS(int day, ll money, ll stock_cnt, ll loan) {
	if (day == N) {
		money += P[day] * stock_cnt;
		ans = max(ans, money);
		return;
	}
	// 매도 X, 매수 X
	if (true) {
		DFS(day + 1, money, stock_cnt, loan);
	}
	// 매도 X, 매수 O
	if (true) {
		ll nmoney = money;
		ll nstock_cnt = stock_cnt;
		ll nloan = loan;
		if (nloan != 0) {
			ll pos = min(nmoney, nloan);
			nmoney -= pos;
			nloan -= pos;
		}
		if (nloan == 0) {
			nloan = nmoney * K;
			nmoney += nloan;
		}
		ll add = nmoney / P[day];
		if (nloan != 0 && add != 0) {
			nstock_cnt += add;
			nmoney -= add * P[day];
			DFS(day + 1, nmoney, nstock_cnt, nloan);
		}
	}
	// 매도 O, 매수 X
	if (true) {
		ll nmoney = money;
		ll nstock_cnt = stock_cnt;
		ll nloan = loan;
		nmoney += P[day] * nstock_cnt;
		nstock_cnt = 0;
		DFS(day + 1, nmoney, nstock_cnt, nloan);
	}
	// 매도 O, 매수 O
	if (true) {
		ll nmoney = money;
		ll nstock_cnt = stock_cnt;
		ll nloan = loan;
		nmoney += P[day] * nstock_cnt;
		nstock_cnt = 0;

		if (nloan != 0) {
			ll pos = min(nmoney, nloan);
			nmoney -= pos;
			nloan -= pos;
		}
		if (nloan == 0) {
			nloan = nmoney * K;
			nmoney += nloan;
		}
		ll add = nmoney / P[day];
		if (nloan != 0 && add != 0) {
			nstock_cnt += add;
			nmoney -= add * P[day];
			DFS(day + 1, nmoney, nstock_cnt, nloan);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		cin >> P[i];
	}
	DFS(1, M, 0, 0);
	cout << ans;

	return 0;
}