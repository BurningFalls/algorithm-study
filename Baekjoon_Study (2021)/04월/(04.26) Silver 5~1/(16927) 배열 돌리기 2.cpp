#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
ll R;
int arr[302][302];
int ch[302][302];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void Rotate() {
	FOR(k, 1, min(N, M) / 2) {
		int cnt = (N + M - 4 * k + 2) * 2;
		int r = R % cnt;
		while (r--) {
			int y = k, x = k;
			int dir = 0;
			int tmp = arr[y][x];
			while (true) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny == k && nx == k) {
					arr[y][x] = tmp;
					break;
				}
				if (ny < k || nx < k || ny > N - k + 1 || nx > M - k + 1) {
					dir = dir + 1;
					continue;
				}
				arr[y][x] = arr[ny][nx];
				y = ny;
				x = nx;
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> R;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
		}
	}
	Rotate();
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}