#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int H[501][501];

int main() {
	FASTIO;
	int N, M, B;
	int minimum = 257, maximum = 0;
	int ans1 = -1, ans2;
	cin >> N >> M >> B;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> H[i][j];
			minimum = min(minimum, H[i][j]);
			maximum = max(maximum, H[i][j]);
		}
	}
	FOR(h, minimum, maximum) {
		int block_rm = 0;
		int block_add = 0;
		int time = 0;
		FOR(i, 1, N) {
			FOR(j, 1, M) {
				if (h < H[i][j]) {
					block_rm += H[i][j] - h;
				}
				else if (h > H[i][j]) {
					block_add += h - H[i][j];
				}
			}
		}
		time = 2 * block_rm + block_add;
		if (B + block_rm - block_add >= 0) {
			if (ans1 == -1) {
				ans1 = time;
				ans2 = h;
			}
			else {
				if (ans1 >= time) {
					ans1 = time;
					ans2 = h;
				}
			}
		}
	}
	cout << ans1 << " " << ans2;

	return 0;
}