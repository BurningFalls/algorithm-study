#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 10

int N, M, K;
vector<vector<char>> Map(MAX, vector<char>(MAX));
map<string, int> mp;
vector<int> dy = { -1, -1, -1, 0, 0, 1, 1, 1 };
vector<int> dx = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<int> Move(5);

void DFS(int node, int y, int x, string s) {
	s += Map[y][x];
	mp[s]++;
	if (node == 4) return;
	FOR(i, 0, 7) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny == N) ny = 0;
		else if (ny == -1) ny = N - 1;
		if (nx == M) nx = 0;
		else if (nx == -1) nx = M - 1;
		DFS(node + 1, ny, nx, s);
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}
	
	FOR(sy, 0, N - 1) {
		FOR(sx, 0, M - 1) {
			DFS(0, sy, sx, "");
		}
	}

	FOR(i, 0, K - 1) {
		string s;
		cin >> s;
		if (!mp.count(s)) {
			cout << 0;
		}
		else {
			cout << mp[s];
		}
		cout << "\n";
	}

	return 0;
}