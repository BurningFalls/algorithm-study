#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct BLOCK {
	int love;
	int empty;
	int col;
	int row;
};

int arr[5];
int Map[21][21] = { 0, };
BLOCK block[21][21];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int inf[401][4];

bool cmp(BLOCK a, BLOCK b) {
	if (a.love == b.love) {
		if (a.empty == b.empty) {
			if (a.col == b.col) {
				return a.row < b.row;
			}
			return a.col < b.col;
		}
		return a.empty > b.empty;
	}
	return a.love > b.love;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(t, 1, N * N) {
		vector<BLOCK> v;
		int p, a, b, c, d;
		cin >> p >> a >> b >> c >> d;
		inf[p][0] = a, inf[p][1] = b, inf[p][2] = c, inf[p][3] = d;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (Map[i][j] != 0) continue;
				int cnt_love = 0, cnt_empty = 0;
				FOR(k, 0, 3) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
					if (Map[ny][nx] == 0)
						cnt_empty++;
					else if (Map[ny][nx] == a || Map[ny][nx] == b || Map[ny][nx] == c || Map[ny][nx] == d)
						cnt_love++;
				}
				v.push_back({ cnt_love, cnt_empty, i, j });
			}
		}
		sort(v.begin(), v.end(), cmp);
		Map[v[0].col][v[0].row] = p;
	}
	int ans = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int cnt = 0;
			FOR(k, 0, 3) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
				int per = Map[i][j];
				if (Map[ny][nx] == inf[per][0] || Map[ny][nx] == inf[per][1] || Map[ny][nx] == inf[per][2] || Map[ny][nx] == inf[per][3])
					cnt++;
			}
			if (cnt != 0)
				ans += pow(10, cnt - 1);
		}
	}
	cout << ans;

	return 0;
}