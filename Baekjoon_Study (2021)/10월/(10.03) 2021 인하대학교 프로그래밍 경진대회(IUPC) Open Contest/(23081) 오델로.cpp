#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int N;
char arr[501][501];
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int Do(int sy, int sx) {
	int y, x;
	int ans = 0;
	FOR(i, 0, 7) {
		int cnt = 0;
		y = sy, x = sx;
		while (true) {
			y += dy[i];
			x += dx[i];
			if (y >= N || x >= N || y < 0 || x < 0) {
				cnt = 0;
				break;
			}
			if (arr[y][x] == '.') {
				cnt = 0;
				break;
			}
			if (arr[y][x] == 'W')
				cnt++;
			else if (arr[y][x] == 'B')
				break;
		}
		ans += cnt;
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> arr[i][j];
		}
	}
	int maxi = 0;
	int ay = 0, ax = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			if (arr[i][j] == 'B' || arr[i][j] == 'W') continue;
			int tmp = Do(i, j);
			if (maxi < tmp) {
				maxi = tmp;
				ay = i;
				ax = j;
			}
		}
	}
	if (maxi == 0)
		cout << "PASS";
	else
		cout << ax << " " << ay << "\n" << maxi;

	return 0;
}