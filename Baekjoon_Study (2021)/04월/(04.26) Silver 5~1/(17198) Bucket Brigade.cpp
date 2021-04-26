#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct POS {
	int y;
	int x;
};

int main() {
	FASTIO;
	char Map[12][12];
	POS B, R, L;
	FOR(i, 1, 10) {
		FOR(j, 1, 10) {
			cin >> Map[i][j];
			if (Map[i][j] == 'B')
				B = { i, j };
			else if (Map[i][j] == 'R')
				R = { i, j };
			else if (Map[i][j] == 'L')
				L = { i, j };
		}
	}
	int ans = abs(L.x - B.x) + abs(L.y - B.y);
	if ((B.x == R.x && R.x == L.x && ((B.y < R.y && R.y < L.y) || (L.y < R.y && R.y < B.y))) ||
		(B.y == R.y && R.y == L.y && ((B.x < R.x && R.x < L.x) || (L.x < R.x && R.x < B.x))))
		cout << ans + 1;
	else
		cout << ans - 1;

	return 0;
}