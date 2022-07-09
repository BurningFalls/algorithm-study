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
	int a, b, c, d;
	int N;
	cin >> a >> b >> c >> d;
	cin >> N;

	int cnt = 0;
	FOR(i, 1, N) {
		int u, v;
		cin >> u >> v;
		cnt += (a * (v - b) * (v - b) + c == u);
	}
	cout << cnt;

	return 0;
}