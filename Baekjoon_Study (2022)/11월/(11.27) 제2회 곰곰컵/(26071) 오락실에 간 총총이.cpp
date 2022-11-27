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
	int N;
	cin >> N;
	vector<vector<char>> Map(N, vector<char>(N));
	set<int> yval, xval;
	int minx = N - 1, maxx = 0;
	int miny = N - 1, maxy = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 'G') {
				minx = min(minx, j);
				maxx = max(maxx, j);
				xval.insert(j);
				miny = min(miny, i);
				maxy = max(maxy, i);
				yval.insert(i);
			}
		}
	}

	int t1 = (LEN(xval) == 1 ? 0 : min(maxx, N - 1 - minx));
	int t2 = (LEN(yval) == 1 ? 0 : min(maxy, N - 1 - miny));
	cout << t1 + t2;

	return 0;
}