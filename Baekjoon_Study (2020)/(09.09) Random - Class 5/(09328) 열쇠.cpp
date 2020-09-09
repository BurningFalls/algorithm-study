#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int H, W;
char Map[102][102];
bool key[26] = { 0, };
vector<pair<int, int>> v[26];
queue<pair<int, int>> q;
bool visited[101][101] = { 0, };
int ans;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void Decide(int y, int x) {
	if (Map[y][x] == '*')
		return;
	if (Map[y][x] == '.') {
		q.push({ y, x });
		visited[y][x] = 1;
	}
	else if (Map[y][x] == '$') {
		q.push({ y, x });
		visited[y][x] = 1;
		ans++;
	}
	else if (Map[y][x] >= 'a' && Map[y][x] <= 'z') {
		q.push({ y, x });
		int k = Map[y][x] - 'a';
		key[k] = 1;
		int len = v[k].size();
		while (!v[k].empty()) {
			q.push({ v[k].back().first, v[k].back().second });
			visited[v[k].back().first][v[k].back().second] = 1;
			v[k].pop_back();
		}
		visited[y][x] = 1;
	}
	else if (Map[y][x] >= 'A' && Map[y][x] <= 'Z') {
		if (key[Map[y][x] - 'A']) {
			q.push({ y, x });
			visited[y][x] = 1;
		}
		else {
			v[Map[y][x] - 'A'].push_back({ y, x });
		}
	}
}

void BFS() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
			if (visited[ny][nx]) continue;
			Decide(ny, nx);
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> H >> W;
		ans = 0;
		while (!q.empty()) q.pop();
		FOR(i, 0, 25) {
			key[i] = 0;
			v[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				cin >> Map[i][j];
			}
		}
		string s;
		cin >> s;
		if (s != "0") {
			FOR(i, 0, s.size() - 1) {
				key[s[i] - 'a'] = 1;
			}
		}
		FOR(i, 1, W) {
			Decide(1, i);
			Decide(H, i);
		}
		FOR(i, 2, H - 1) {
			Decide(i, 1);
			Decide(i, W);
		}
		BFS();
		cout << ans << "\n";
	}

	return 0;
}