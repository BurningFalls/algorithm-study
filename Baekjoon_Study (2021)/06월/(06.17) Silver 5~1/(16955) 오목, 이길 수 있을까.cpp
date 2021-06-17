#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[11][11];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool Check(int arr[8]) {
	if (arr[0] + arr[7] >= 4)
		return true;
	if (arr[1] + arr[6] >= 4)
		return true;
	if (arr[2] + arr[5] >= 4)
		return true;
	if (arr[3] + arr[4] >= 4)
		return true;
	return false;
}

int main() {
	FASTIO;
	FOR(i, 1, 10) {
		FOR(j, 1, 10) {
			cin >> Map[i][j];
		}
	}
	bool ans = false;
	FOR(i, 1, 10) {
		FOR(j, 1, 10) {
			if (Map[i][j] != '.') continue;
			int cnt[8] = { 0, };
			FOR(k, 0, 7) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				int tmp = 0;
				while (ny >= 1 && ny <= 10 && nx >= 1 && nx <= 10) {
					if (Map[ny][nx] == 'X') {
						tmp++;
						ny += dy[k];
						nx += dx[k];
					}
					else
						break;
				}
				cnt[k] = tmp;
			}
			ans |= (Check(cnt));
		}
	}
	cout << ans;

	return 0;
}