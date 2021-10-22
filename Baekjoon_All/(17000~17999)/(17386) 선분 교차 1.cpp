#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int CCW(pll a, pll b, pll c) {
	ll t1 = a.first * b.second + b.first * c.second + c.first * a.second;
	ll t2 = b.first * a.second + c.first * b.second + a.first * c.second;
	if (t1 - t2 > 0)
		return 1;
	else if (t1 - t2 == 0)
		return 0;
	else if (t1 - t2 < 0)
		return -1;
}

int main() {
	FASTIO;
	pll arr[4];
	FOR(i, 0, 3) {
		cin >> arr[i].first >> arr[i].second;
	}
	int ABC = CCW(arr[0], arr[1], arr[2]);
	int ABD = CCW(arr[0], arr[1], arr[3]);
	int CDA = CCW(arr[2], arr[3], arr[0]);
	int CDB = CCW(arr[2], arr[3], arr[1]);
	cout << (ABC * ABD <= 0 && CDA * CDB <= 0);

	return 0;
}