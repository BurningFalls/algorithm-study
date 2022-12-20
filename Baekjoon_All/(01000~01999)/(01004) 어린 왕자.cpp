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
	int T;
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int N;
		cin >> N;
		int cnt = 0;
		FOR(i, 1, N) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			bool f1 = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) <= r * r;
			bool f2 = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) <= r * r;
			cnt += (f1 ^ f2);
		}
		cout << cnt << "\n";
	}

	return 0;
}