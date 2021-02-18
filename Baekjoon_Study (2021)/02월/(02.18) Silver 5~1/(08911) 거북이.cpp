#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int T;
	int dy[4] = { 1, 0, -1, 0 };
	int dx[4] = { 0, -1, 0, 1 };
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.size();
		int y = 0, x = 0;
		int dir = 0;
		int max_y = 0, min_y = 0;
		int max_x = 0, min_x = 0;
		FOR(i, 0, len - 1) {
			if (s[i] == 'F') {
				y += dy[dir];
				x += dx[dir];
			}
			else if (s[i] == 'B') {
				y -= dy[dir];
				x -= dx[dir];
			}
			else if (s[i] == 'L') {
				dir = (dir + 1) % 4;
			}
			else if (s[i] == 'R') {
				dir = (dir + 3) % 4;
			}
			max_y = max(max_y, y);
			min_y = min(min_y, y);
			max_x = max(max_x, x);
			min_x = min(min_x, x);
		}
		cout << (max_y - min_y) * (max_x - min_x) << "\n";
	}


	return 0;
}