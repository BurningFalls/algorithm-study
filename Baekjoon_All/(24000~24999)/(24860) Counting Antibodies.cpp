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

int main() {
	FASTIO;
	ll v1, j1;
	ll v2, j2;
	ll v3, d3, j3;
	cin >> v1 >> j1;
	cin >> v2 >> j2;
	cin >> v3 >> d3 >> j3;
	cout << (v1 * j1 + v2 * j2) * (v3 * d3 * j3);

	return 0;
}