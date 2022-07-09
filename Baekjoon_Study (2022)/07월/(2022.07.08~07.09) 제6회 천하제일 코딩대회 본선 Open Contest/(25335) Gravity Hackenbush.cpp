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
#define MAX 200001

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
	}
	int r = 0, b = 0, g = 0;
	FOR(i, 1, M) {
		ll v, w;
		char c;
		cin >> v >> w >> c;
		if (c == 'R')
			r++;
		else if (c == 'B')
			b++;
		else if (c == 'G')
			g++;
	}
	if (g % 2 == 0) {
		cout << (r > b ? "jhnah917" : "jhnan917");
	}
	else if (g % 2 == 1) {
		cout << (r >= b ? "jhnah917" : "jhnan917");
	}

	return 0;
}