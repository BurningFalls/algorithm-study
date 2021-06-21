#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int color_cnt[11];
int Map[11][11];

int main() {
	FASTIO;
	int H, W, C;
	cin >> H >> W >> C;
	int sum = 0;
	FOR(i, 1, C) {
		cin >> color_cnt[i];
	}
	int idx = 1;
	FOR(j, 1, W) {
		FOR(i, 1, H) {
			Map[i][j] = idx;
			color_cnt[idx]--;
			if (color_cnt[idx] == 0)
				idx++;
		}
	}
	FOR(i, 1, H) {
		FOR(j, 1, W) {
			cout << Map[i][j];
		}
		cout << "\n";
	}

	return 0;
}