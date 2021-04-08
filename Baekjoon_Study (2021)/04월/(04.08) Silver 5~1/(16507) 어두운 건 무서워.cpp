#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int K[1001][1001];
int sum[1001][1001] = { 0, };

int main() {
	FASTIO;
	int R, C, Q;
	cin >> R >> C >> Q;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> K[i][j];
		}
	}
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + K[i][j] - sum[i - 1][j - 1];
		}
	}
	FOR(i, 1, Q) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int tmp = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
		int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << tmp / cnt << "\n";
	}

	return 0;
}