#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char Map[7][7];
vector<pii> tv;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool Check() {
	for (pii node : tv) {
		int y = node.first;
		int x = node.second;
		bool flag = true;
		FOR(i, 0, 3) {
			int ny = y;
			int nx = x;
			while (true) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) break;
				if (Map[ny][nx] == 'O') break;
				if (Map[ny][nx] == 'S') {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == 'T')
				tv.push_back({ i, j });
		}
	}
	int tmp = N * N - 1;
	bool flag = false;
	FOR(a, 0, tmp) {
		int ay = a / N;
		int ax = a % N;
		if (Map[ay][ax] != 'X') continue;
		FOR(b, a + 1, tmp) {
			int by = b / N;
			int bx = b % N;
			if (Map[by][bx] != 'X') continue;
			FOR(c, b + 1, tmp) {
				int cy = c / N;
				int cx = c % N;
				if (Map[cy][cx] != 'X') continue;
				
				int arr[3] = { a, b, c };
				FOR(i, 0, 2) {
					int y = arr[i] / N;
					int x = arr[i] % N;
					Map[y][x] = 'O';
				}

				if (Check()) {
					flag = true;
					a = tmp;
					b = tmp;
					c = tmp;
				}

				FOR(i, 0, 2) {
					int y = arr[i] / N;
					int x = arr[i] % N;
					Map[y][x] = 'X';
				}
			}
		}
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}