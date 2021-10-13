#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

struct NODE {
	int coin1y;
	int coin1x;
	int coin2y;
	int coin2x;
};

queue<NODE> q;
int visited[21][21][21][21];

int BFS(int N, int M, vvc Map) {
	vector<pii> Coins;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == 'o') {
				Coins.push_back({ i, j });
			}
		}
	}
	NODE coins;
	coins.coin1y = Coins[0].first;
	coins.coin1x = Coins[0].second;
	coins.coin2y = Coins[1].first;
	coins.coin2x = Coins[1].second;
	vi dy = { -1, 1, 0, 0 };
	vi dx = { 0, 0, -1, 1 };
	q.push({ coins });
	visited[coins.coin1y][coins.coin1x][coins.coin2y][coins.coin2x] = 1;
	while (!q.empty()) {
		int c1y = q.front().coin1y;
		int c1x = q.front().coin1x;
		int c2y = q.front().coin2y;
		int c2x = q.front().coin2x;
		q.pop();
		if (visited[c1y][c1x][c2y][c2x] == 11)
			return -1;
		FOR(i, 0, 3) {
			int n1y = c1y + dy[i];
			int n1x = c1x + dx[i];
			int n2y = c2y + dy[i];
			int n2x = c2x + dx[i];
			bool flag1 = false, flag2 = false;
			if (n1y < 1 || n1y > N || n1x < 1 || n1x > M) {
				flag1 = true;
			}
			if (n2y < 1 || n2y > N || n2x < 1 || n2x > M) {
				flag2 = true;
			}
			if (flag1 && flag2) continue;
			if (flag1 || flag2) {
				return visited[c1y][c1x][c2y][c2x];
			}
			if (Map[n1y][n1x] == '#') {
				n1y = c1y; n1x = c1x;
			}
			if (Map[n2y][n2x] == '#') {
				n2y = c2y; n2x = c2x;
			}
			if (visited[n1y][n1x][n2y][n2x]) continue;
			visited[n1y][n1x][n2y][n2x] = visited[c1y][c1x][c2y][c2x] + 1;
			q.push({ n1y, n1x, n2y, n2x });
		}
	}
	return -1;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vvc Map(N + 1, vc(M + 1));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	cout << BFS(N, M, Map);

	return 0;
}