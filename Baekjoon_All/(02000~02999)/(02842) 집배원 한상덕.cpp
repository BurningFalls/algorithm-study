#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N;
int Py = 0, Px = 0;
int Kcnt = 0;
char Map[51][51];
int height[51][51];
bool visited[51][51];
set<int> se;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool BFS(int mini, int maxi) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	q.push({ Py, Px });
	visited[Py][Px] = 1;
	int kcnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(i, 0, 7) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
			if (visited[ny][nx]) continue;
			if (height[ny][nx] < mini || height[ny][nx] > maxi) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
			if (Map[ny][nx] == 'K') {
				kcnt++;
				if (kcnt == Kcnt)
					return true;
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
			if (Map[i][j] == 'P') {
				Py = i;
				Px = j;
			}
			else if (Map[i][j] == 'K')
				Kcnt++;
		}
	}
	int Ph = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> height[i][j];
			if (i == Py && j == Px)
				Ph = height[i][j];
			se.insert(height[i][j]);
		}
	}
	set<int>::iterator left, right;
	left = se.begin();
	right = se.begin();
	int ans = INF;
	while (left != se.end() && right != se.end()) {
		int mini = *left;
		int maxi = *right;
		bool flag = false;
		if (Ph >= mini && Ph <= maxi)
			flag = BFS(mini, maxi);
		if (flag) {
			ans = min(ans, maxi - mini);
			left++;
		}
		else
			right++;
	}
	cout << ans;


	return 0;
}