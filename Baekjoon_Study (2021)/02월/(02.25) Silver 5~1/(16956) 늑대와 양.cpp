#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int R, C;
char Map[502][502];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool Check() {
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (Map[i][j] == 'S') {
				FOR(k, 0, 3) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
					if (Map[ny][nx] == 'W')
						return false;
				}
			}
		}
	}
	return true;
}

int main() {
	FASTIO;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	bool flag = Check();
	cout << flag << "\n";
	if (flag) {
		FOR(i, 1, R) {
			FOR(j, 1, C) {
				if (Map[i][j] == '.')
					cout << "D";
				else
					cout << Map[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}