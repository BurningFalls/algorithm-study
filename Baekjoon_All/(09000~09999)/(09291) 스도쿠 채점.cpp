#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[9][9];

bool Check() {
	FOR(i, 0, 8) {
		bool num[10] = { 0, };
		FOR(j, 0, 8) {
			num[arr[i][j]] = 1;
		}
		FOR(i, 1, 9) {
			if (!num[i])
				return false;
		}
	}
	FOR(i, 0, 8) {
		bool num[10] = { 0, };
		FOR(j, 0, 8) {
			num[arr[j][i]] = 1;
		}
		FOR(i, 1, 9) {
			if (!num[i])
				return false;
		}
	}
	for (int sy = 0; sy <= 6; sy += 3) {
		for (int sx = 0; sx <= 6; sx += 3) {
			bool num[10] = { 0, };
			FOR(i, sy, sy + 2) {
				FOR(j, sx, sx + 2) {
					num[arr[i][j]] = 1;
				}
			}
			FOR(i, 1, 9) {
				if (!num[i])
					return false;
			}
		}
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	int cnt = 0;
	while (T--) {
		cnt++;
		FOR(i, 0, 8) {
			FOR(j, 0, 8) {
				cin >> arr[i][j];
			}
		}
		cout << "Case " << cnt << ": ";
		cout << ((Check()) ? "CORRECT" : "INCORRECT") << "\n";
	}

	return 0;
}