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

int N, K;
int Color[13][13];
deque<int> Map[13][13];
pair<pii, int> Pos[11];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

bool Move(int idx) {
	int y = Pos[idx].first.first;
	int x = Pos[idx].first.second;
	int dir = Pos[idx].second;
	int dir_arr[4] = { 1, 2, 3, 4 };
	int ndir_arr[4] = { 2, 1, 4, 3 };
	if (Map[y][x].front() != idx) {
		return 0;
	}
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (ny < 1 || nx < 1 || ny > N || nx > N || Color[ny][nx] == 2) {
		FOR(i, 0, 3) {
			if (dir_arr[i] == dir) {
				dir = ndir_arr[i];
				Pos[idx].second = ndir_arr[i];
				break;
			}
		}
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (ny < 1 || nx < 1 || ny > N || nx > N || Color[ny][nx] == 2) {
			return 0;
		}
	}
	if (Color[ny][nx] == 1) {
		while (!Map[y][x].empty()) {
			int node = Map[y][x].back();
			Map[y][x].pop_back();
			Map[ny][nx].push_back(node);
			Pos[node].first = { ny, nx };
		}
	}
	else if (Color[ny][nx] == 0) {
		while (!Map[y][x].empty()) {
			int node = Map[y][x].front();
			Map[y][x].pop_front();
			Map[ny][nx].push_back(node);
			Pos[node].first = { ny, nx };
		}
	}
	return (LEN(Map[ny][nx]) >= 4);
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Color[i][j];
		}
	}
	FOR(k, 1, K) {
		int r, c, d;
		cin >> r >> c >> d;
		Pos[k] = { {r, c}, d };
		Map[r][c].push_back(k);
	}
	int turn = 1;
	while (turn <= 1000) {
		bool flag = true;
		FOR(i, 1, K) {
			if (Move(i)) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			break;
		}
		turn++;
	}
	cout << (turn <= 1000 ? turn : -1);

	return 0;
}