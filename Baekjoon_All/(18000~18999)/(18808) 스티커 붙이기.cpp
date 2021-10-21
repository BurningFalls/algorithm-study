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

int N, M, K;
bool Map[40][40] = { 0, };
int R, C;
bool Sticker[10][10];

void Rotate(int& R, int& C) {
	bool tmp[10][10];
	FOR(i, 0, R - 1) {
		FOR(j, 0, C - 1) {
			tmp[j][R - 1 - i] = Sticker[i][j];
		}
	}
	swap(R, C);
	FOR(i, 0, R - 1) {
		FOR(j, 0, C - 1) {
			Sticker[i][j] = tmp[i][j];
		}
	}
}

void Paste(int R, int C) {
	FOR(r, 0, 3) {
		FOR(sy, 0, N - 1) {
			FOR(sx, 0, M - 1) {
				bool flag = true;
				if (sy + R - 1 > N - 1) continue;
				if (sx + C - 1 > M - 1) continue;
				FOR(i, sy, sy + R - 1) {
					FOR(j, sx, sx + C - 1) {
						if (Sticker[i - sy][j - sx] == 0) continue;
						if (Map[i][j] == 1) {
							flag = false;
						}
					}
				}
				if (flag) {
					FOR(i, sy, sy + R - 1) {
						FOR(j, sx, sx + C - 1) {
							if (Sticker[i - sy][j - sx] == 0) continue;
							Map[i][j] = 1;
						}
					}
					return;
				}
			}
		}
		if (r != 3) {
			Rotate(R, C);
		}
	}
}

int Counting() {
	int cnt = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			if (Map[i][j] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(k, 1, K) {
		cin >> R >> C;
		FOR(i, 0, R - 1) {
			FOR(j, 0, C - 1) {
				cin >> Sticker[i][j];
			}
		}
		Paste(R, C);
	}
	cout << Counting();


	return 0;
}