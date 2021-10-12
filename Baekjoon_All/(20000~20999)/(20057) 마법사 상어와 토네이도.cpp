#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

pii RCP(pii x, int N) {
	return { x.second, N + 1 - x.first };
}

pii CP(pii x, int N) {
	return { N + 1 - x.second, x.first };
}

int Do(int N, int y, int x, int dir, vector<vector<int>>& Sand) {
	vector<int> dy = { -2, -1, -1, -1, 0, 1, 1, 1, 2, 0 };
	vector<int> dx = { 0, -1, 0, 1, -2, -1, 0, 1, 0, -1 };
	vector<int> val = { 2, 10, 7, 1, 5, 10, 7, 1, 2, 0 };
	int rest_sand = Sand[y][x];
	int out_of = 0;
	FOR(i, 0, 9) {
		int ny = 0, nx = 0;
		if (dir == 0) {
			ny = y + dy[i];
			nx = x + dx[i];
		}
		else if (dir == 1) {
			pii tmp = RCP({ y, x }, N);
			tmp.first += dy[i];
			tmp.second += dx[i];
			tmp = CP(tmp, N);
			ny = tmp.first;
			nx = tmp.second;
		}
		else if (dir == 2) {
			pii tmp = RCP({ y, x }, N);
			tmp = RCP(tmp, N);
			tmp.first += dy[i];
			tmp.second += dx[i];
			tmp = CP(tmp, N);
			tmp = CP(tmp, N);
			ny = tmp.first;
			nx = tmp.second;
		}
		else if (dir == 3) {
			pii tmp = CP({ y, x }, N);
			tmp.first += dy[i];
			tmp.second += dx[i];
			tmp = RCP(tmp, N);
			ny = tmp.first;
			nx = tmp.second;
		}
		int sand = 0;
		if (i == 9) {
			sand = rest_sand;
		}
		else {
			sand = Sand[y][x] * val[i] / 100;
		}
		if (ny < 1 || nx < 1 || ny > N || nx > N) {
			out_of += sand;
		}
		else {
			Sand[ny][nx] += sand;
		}
		rest_sand -= sand;
	}
	return out_of;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<vector<int>> Sand(N + 1, vector<int>(N + 1));
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Sand[i][j];
		}
	}
	int y = N / 2 + 1;
	int x = N / 2 + 1;
	int len = 1;
	int len_cnt = 0;
	int cnt = 0;
	vector<int> dy = { 0, 1, 0, -1 };
	vector<int> dx = { -1, 0, 1, 0 };
	int dir = 0;
	int ans = 0;
	while (!((y == 1) && (x == 0))) {
		y += dy[dir];
		x += dx[dir];
		ans += Do(N, y, x, dir, Sand);
		cnt++;
		if (cnt == len) {
			dir = (dir + 1) % 4;
			len_cnt++;
			if (len_cnt == 2) {
				len++;
				len_cnt = 0;
			}
			cnt = 0;
		}
	}
	cout << ans;

	return 0;
}