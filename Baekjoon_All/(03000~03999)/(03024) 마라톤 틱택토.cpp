#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char Map[31][31];

char Check(int a, int b, int c) {
	int ay, ax, by, bx, cy, cx;
	ay = a / N, ax = a % N;
	by = b / N, bx = b % N;
	cy = c / N, cx = c % N;
	if ((ay == by && by == cy && ax + 1 == bx && bx + 1 == cx) ||
		(ay + 1 == by && by + 1 == cy && ax == bx && bx == cx) ||
		(ay + 1 == by && by + 1 == cy && ax + 1 == bx && bx + 1 == cx) ||
		(ay + 1 == by && by + 1 == cy && ax - 1 == bx && bx - 1 == cx)) {
		if (Map[ay][ax] == Map[by][bx] && Map[by][bx] == Map[cy][cx])
			return Map[ay][ax];
	}
	return '.';
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 0, N * N - 1) {
		FOR(j, i + 1, N * N - 1) {
			FOR(k, j + 1, N * N - 1) {
				char t = Check(i, j, k);
				if (t != '.') {
					cout << t;
					return 0;
				}
			}
		}
	}
	cout << "ongoing";


	return 0;
}