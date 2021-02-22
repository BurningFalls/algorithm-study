#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int R, C, N;
int timing[202][202] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	FASTIO;
	char x;
	cin >> R >> C >> N;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> x;
			if (x == 'O')
				timing[i][j] = 1;
		}
	}
	queue<pii> q;
	FOR(t, 2, N) {
		FOR(i, 1, R) {
			FOR(j, 1, C) {
				timing[i][j] += 1;
				if (timing[i][j] == 3) {
					q.push({ i, j });
				}
			}
		}
		if (t % 2 == 1) {
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				timing[y][x] = 0;
				FOR(i, 0, 3) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
					timing[ny][nx] = 0;
				}
			}
		}
	}
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (timing[i][j] == 0)
				cout << ".";
			else
				cout << "O";
		}
		cout << "\n";
	}
	

	return 0;
}