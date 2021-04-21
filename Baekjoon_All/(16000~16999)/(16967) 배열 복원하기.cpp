#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int ans[602][602];

int main() {
	FASTIO;
	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	FOR(i, 1, H + X) {
		FOR(j, 1, W + Y) {
			int num;
			cin >> num;
			if (X <= i && i <= H && Y <= j && j <= W) {
				ans[i][j] = num - ans[i - X][j - Y];
			}
			else {
				ans[i][j] = num;
			}
		}
	}
	FOR(i, 1, H) {
		FOR(j, 1, W) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}