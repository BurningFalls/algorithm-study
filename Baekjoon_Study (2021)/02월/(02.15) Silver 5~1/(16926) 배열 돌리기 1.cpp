#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

int N, M, R;
int arr[301][301];
vector<int> v;

void Get(int y, int x) {
	int sy = y, sx = x;
	while (x < M - (sx - 1)) {
		v.push_back(arr[y][x]);
		x++;
	}
	while (y < N - (sy - 1)) {
		v.push_back(arr[y][x]);
		y++;
	}
	while (x > 1 + (sx - 1)) {
		v.push_back(arr[y][x]);
		x--;
	}
	while (y > 1 + (sy - 1)) {
		v.push_back(arr[y][x]);
		y--;
	}
}

void Set(int y, int x) {
	int len = v.size();
	int pos = R % len;
	int sy = y, sx = x;
	while (x < M - (sx - 1)) {
		arr[y][x] = v[pos];
		x++;
		pos++;
		pos %= len;
	}
	while (y < N - (sy - 1)) {
		arr[y][x] = v[pos];
		y++;
		pos++;
		pos %= len;
	}
	while (x > 1 + (sx - 1)) {
		arr[y][x] = v[pos];
		x--;
		pos++;
		pos %= len;
	}
	while (y > 1 + (sy - 1)) {
		arr[y][x] = v[pos];
		y--;
		pos++;
		pos %= len;
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
	FOR(i, 1, min(N, M) / 2) {
		v.clear();
		Get(i, i);
		Set(i, i);
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}