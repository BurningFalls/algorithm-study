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

int N, M, K;
vector<vector<pii>> Map_Smell(21, vector<pii>(21, { 0, 0 }));
vector<vector<vector<int>>> Map_Shark(21, vector<vector<int>>(21));
vector<pair<pii, int>> Shark(401);
vector<int> dy = { 0, -1, 1, 0, 0 };
vector<int> dx = { 0, 0, 0, -1, 1 };
vector<vector<vector<int>>> Direct(401, vector<vector<int>>(5, vector<int>(4)));


void Smell_In() {
	FOR(i, 1, M) {
		if (Shark[i].second == 0) continue;
		int y = Shark[i].first.first;
		int x = Shark[i].first.second;
		Map_Smell[y][x] = { i, K };
	}
}

void Smell_Out() {
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Map_Smell[i][j].first == 0) continue;
			if (--Map_Smell[i][j].second == 0) {
				Map_Smell[i][j].first = 0;
			}
		}
	}
}

void Move() {
	FOR(i, 1, M) {
		if (Shark[i].second == 0) continue;
		int y = Shark[i].first.first;
		int x = Shark[i].first.second;
		int dir = Shark[i].second;
		int ndir = -1;
		int d, ny, nx;
		FOR(j, 0, 3) {
			d = Direct[i][dir][j];
			ny = y + dy[d];
			nx = x + dx[d];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (Map_Smell[ny][nx].first != 0) continue;
			ndir = d;
			break;
		}
		if (ndir == -1) {
			FOR(j, 0, 3) {
				d = Direct[i][dir][j];
				ny = y + dy[d];
				nx = x + dx[d];
				if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
				if (Map_Smell[ny][nx].first != i) continue;
				ndir = d;
				break;
			}
		}
		ny = y + dy[ndir];
		nx = x + dx[ndir];
		Shark[i] = { {ny, nx}, ndir };
		Map_Shark[y][x].pop_back();
		Map_Shark[ny][nx].push_back(i);
	}
}

void Fight() {
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Map_Shark[i][j].empty()) continue;
			sort(ALL(Map_Shark[i][j]));
			while (LEN(Map_Shark[i][j]) != 1) {
				int node = Map_Shark[i][j].back();
				Map_Shark[i][j].pop_back();
				Shark[node] = { {0, 0}, 0 };
			}
		}
	}
}

bool Check() {
	int alive = 0;
	FOR(i, 1, M) {
		if (Shark[i].second == 0) continue;
		alive++;
	}
	return (alive == 1);
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int num;
			cin >> num;
			if (num != 0) {
				Shark[num].first = { i, j };
				Map_Shark[i][j].push_back(num);
			}
		}
	}
	FOR(i, 1, M) {
		cin >> Shark[i].second;
	}
	FOR(i, 1, M) {
		FOR(j, 1, 4) {
			FOR(k, 0, 3) {
				cin >> Direct[i][j][k];
			}
		}
	}
	int time = 0;
	while (time <= 1000 && !Check()) {
		Smell_In();
		Move();
		Smell_Out();
		Fight();
		time++;
	}
	cout << (time <= 1000 ? time : -1);

	return 0;
}