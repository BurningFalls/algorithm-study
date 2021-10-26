#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int main() {
	FASTIO;
	int R, C;
	char Map[26][26];
	int Update[26][26] = { 0, };
	int dy[4] = { -1, 0, 1, 0 };
	int dx[4] = { 0, -1, 0, 1 };
	char block[7] = { '|', '-', '+', '1', '2', '3', '4' };
	int dir[7] = { 5, 10, 15, 12, 9, 3, 6 };
	
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}

	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (Map[i][j] == '.' || Map[i][j] == 'M' || Map[i][j] == 'Z') continue;
			int idx = 0;
			FOR(k, 0, 6) {
				if (Map[i][j] == block[k]) {
					idx = k;
				}
			}
			FOR(k, 0, 3) {
				if (dir[idx] & (1 << k)) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (Map[ny][nx] != '.') continue;
					int ndir = (k + 2) % 4;
					Update[ny][nx] += (1 << ndir);
				}
			}
		}
	}

	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (Update[i][j] == 0) continue;
			FOR(k, 0, 6) {
				if (Update[i][j] == dir[k]) {
					cout << i << " " << j << " " << block[k];
				}
			}
		}
	}


	return 0;
}