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
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N;
int Map[2][6][4] = { 0, };

int Find_idx(int kind, int y, int x) {
	int idx = 0;
	while (idx <= 5 && Map[kind][idx][x] == 0) {
		idx++;
	}
	return idx - 1;
}

void Drop(int t, int y, int x) {
	int idx1, idx2;
	if (t == 1) {
		idx1 = Find_idx(0, y, x);
		Map[0][idx1][x] = 1;
		idx1 = Find_idx(1, x, 3 - y);
		Map[1][idx1][3 - y] = 1;
	}
	else if (t == 2) {
		idx1 = Find_idx(0, y, x);
		idx2 = Find_idx(0, y, x + 1);
		Map[0][min(idx1, idx2)][x] = 1;
		Map[0][min(idx1, idx2)][x + 1] = 1;
		idx1 = Find_idx(1, x + 1, 3 - y);
		Map[1][idx1 - 1][3 - y] = 1;
		Map[1][idx1][3 - y] = 1;
	}
	else if (t == 3) {
		idx1 = Find_idx(0, y + 1, x);
		Map[0][idx1 - 1][x] = 1;
		Map[0][idx1][x] = 1;
		idx1 = Find_idx(1, x, 2 - y);
		idx2 = Find_idx(1, x, 3 - y);
		Map[1][min(idx1, idx2)][2 - y] = 1;
		Map[1][min(idx1, idx2)][3 - y] = 1;
	}
}

int Scoring() {
	int score = 0;
	FOR(m, 0, 1) {
		FOR(i, 0, 5) {
			int cnt = 0;
			FOR(j, 0, 3) {
				if (Map[m][i][j] == 1) {
					cnt++;
				}
			}
			if (cnt == 4) {
				FOR(j, 0, 3) {
					Map[m][i][j] = 0;
				}
				score++;
			}
		}
	}
	return score;
}

void Gravity() {
	FOR(m, 0, 1) {
		vector<int> v;
		ROF(i, 5, 0) {
			int cnt = 0;
			FOR(j, 0, 3) {
				if (Map[m][i][j] == 0) {
					cnt++;
				}
			}
			if (cnt != 4) {
				v.push_back(i);
			}
		}
		FOR(i, 0, LEN(v) - 1) {
			FOR(j, 0, 3) {
				Map[m][5 - i][j] = Map[m][v[i]][j];
			}
		}
		FOR(i, LEN(v), 5) {
			FOR(j, 0, 3) {
				Map[m][5 - i][j] = 0;
			}
		}
	}
}

void Limit() {
	FOR(m, 0, 1) {
		int row_cnt = 0;
		FOR(i, 0, 1) {
			int cnt = 0;
			FOR(j, 0, 3) {
				if (Map[m][i][j] == 0) {
					cnt++;
				}
			}
			if (cnt != 4) {
				row_cnt++;
			}
		}
		ROF(i, 5, 6 - row_cnt) {
			FOR(j, 0, 3) {
				Map[m][i][j] = 0;
			}
		}
	}
}

int Counting() {
	int cnt = 0;
	FOR(m, 0, 1) {
		FOR(i, 0, 5) {
			FOR(j, 0, 3) {
				if (Map[m][i][j] == 1) {
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	int score = 0;
	cin >> N;
	FOR(i, 1, N) {
		int t, y, x;
		cin >> t >> y >> x;
		Drop(t, y, x);
		score += Scoring();
		Gravity();
		Limit();
		Gravity();
	}
	cout << score << "\n" << Counting();

	return 0;
}