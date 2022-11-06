#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

struct NODE {
	int lev;
	int y;
	int x;

	bool operator<(const NODE& a) const {
		return lev > a.lev;
	}
};

int N, M, L, E, K;
int sy, sx;
vector<vector<int>> Map(101, vector<int>(101));
vector<vector<bool>> visited(101, vector<bool>(101, 0));
bool end_pos = false;

void Move() {
	PQ<NODE> pq;
	vector<int> dy = { -1, 1, 0, 0 };
	vector<int> dx = { 0, 0, -1, 1 };
	pq.push({ 0, sy, sx });
	visited[sy][sx] = 1;
	while (!pq.empty()) {
		int lev = pq.top().lev;
		int y = pq.top().y;
		int x = pq.top().x;
		pq.pop();
		if (L <= lev) {
			return;
		}
		while (E + lev >= L) {
			lev -= (L - E);
			E = 0;
			L++;
		}
		E += lev;
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (Map[ny][nx] == -1) continue;
			if (Map[ny][nx] == -2) {
				end_pos = true;
				continue;
			}
			visited[ny][nx] = 1;
			pq.push({ Map[ny][nx], ny, nx });
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> L >> E >> K;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == -3) {
				sy = i; sx = j;
			}
		}
	}
	Move();
	cout << (end_pos && L >= K ? 'O' : 'X');

	return 0;
}