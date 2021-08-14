#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int sum[1025][1025] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int num;
			cin >> num;
			sum[i][j] = sum[i][j - 1] + num;
		}
	}
	FOR(i, 1, M) {
		int w;
		cin >> w;
		if (w == 0) {
			int y, x, c;
			cin >> y >> x >> c;
			int diff = c - (sum[y][x] - sum[y][x - 1]);
			FOR(j, x, N)
				sum[y][j] += diff;
		}
		else if (w == 1) {
			int y1, x1, y2, x2;
			cin >> y1 >> x1 >> y2 >> x2;
			int tmp = 0;
			FOR(j, y1, y2) {
				tmp += (sum[j][x2] - sum[j][x1 - 1]);
			}
			cout << tmp << "\n";
		}
	}


	return 0;
}