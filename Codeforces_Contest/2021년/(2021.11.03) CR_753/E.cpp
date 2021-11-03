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

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		string order;
		cin >> N >> M;
		cin >> order;
		int miny = 0, maxy = 0;
		int minx = 0, maxx = 0;
		int y = 0, x = 0;
		FOR(i, 0, LEN(order) - 1) {
			int ny = y, nx = x;
			if (order[i] == 'L') {
				nx--;
			}
			else if (order[i] == 'R') {
				nx++;
			}
			else if (order[i] == 'D') {
				ny++;
			}
			else if (order[i] == 'U') {
				ny--;
			}
			int leny = max(maxy, ny) - min(miny, ny) + 1;
			int lenx = max(maxx, nx) - min(minx, nx) + 1;
			if (leny > N || lenx > M) {
				break;
			}
			y = ny, x = nx;
			miny = min(miny, y);
			maxy = max(maxy, y);
			minx = min(minx, x);
			maxx = max(maxx, x);
		}
		cout << 1 - miny << " " << 1 - minx << "\n";
	}

	return 0;
}