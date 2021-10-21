#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, M;
int Map[50][50];
int tmp[50][50];
int Cloud[50][50] = { 0, };
vector<pii> inc_pos;

void Raining(int d, int s) {
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			tmp[i][j] = Cloud[i][j];
			Cloud[i][j] = 0;
		}
	}
	int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
	int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
	s %= N;
	inc_pos.clear();
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			if (tmp[i][j] == 0) continue;
			int ny = (i + dy[d] * s + N) % N;
			int nx = (j + dx[d] * s + N) % N;
			Cloud[ny][nx] = -1;
			Map[ny][nx]++;
			inc_pos.push_back({ ny, nx });
		}
	}
}

void Magic() {
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			tmp[i][j] = Map[i][j];
		}
	}
	int dy[4] = { -1, -1, 1, 1 };
	int dx[4] = { 1, -1, 1, -1 };
	FOR(i, 0, LEN(inc_pos) - 1) {
		int cnt = 0;
		int y = inc_pos[i].first;
		int x = inc_pos[i].second;
		FOR(j, 0, 3) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (Map[ny][nx] == 0) continue;
			cnt++;
		}
		tmp[y][x] += cnt;
	}
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			Map[i][j] = tmp[i][j];
		}
	}
}

void Clouding() {
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			if (Cloud[i][j] == -1) {
				Cloud[i][j] = 0;
				continue;
			}
			if (Map[i][j] < 2) continue;
			Cloud[i][j] = 1;
			Map[i][j] -= 2;
		}
	}
}

int Counting() {
	int sum = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			sum += Map[i][j];
		}
	}
	return sum;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
		}
	}
	FOR(i, N - 2, N - 1) {
		FOR(j, 0, 1) {
			Cloud[i][j] = 1;
		}
	}
	FOR(m, 1, M) {
		int d, s;
		cin >> d >> s;
		Raining(d, s);
		Magic();
		Clouding();
	}
	cout << Counting();

	return 0;
}