#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000 + 1

int W, H;
char Map[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<pii> player_q;
queue<pii> fire_q;

void Spread_Fire() {
	int len = fire_q.size();
	FOR(i, 1, len) {
		int y = fire_q.front().first;
		int x = fire_q.front().second;
		fire_q.pop();
		FOR(j, 0, 3) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
			if (Map[ny][nx] != '@' && visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			fire_q.push({ ny, nx });
		}
	}
}

int Move_Player() {
	bool flag = false;
	int len = player_q.size();
	FOR(i, 1, len) {
		int y = player_q.front().first;
		int x = player_q.front().second;
		player_q.pop();
		if (y == 1 || y == H || x == 1 || x == W)
			return 2;
		FOR(j, 0, 3) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
			if (Map[ny][nx] != '@' && visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			player_q.push({ ny, nx });
			flag = true;
		}
	}
	return flag;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		while (!player_q.empty()) player_q.pop();
		while (!fire_q.empty()) fire_q.pop();
		memset(visited, 0, sizeof(visited));
		cin >> W >> H;
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				cin >> Map[i][j];
				if (Map[i][j] == '@')
					player_q.push({ i, j });
				else if (Map[i][j] == '*')
					fire_q.push({ i, j });
				if (Map[i][j] != '.')
					visited[i][j] = 1;
			}
		}
		int flag = false;
		int cnt = 0;
		while (true) {
			Spread_Fire();
			int temp = Move_Player();
			cnt++;
			if (temp == 2) {
				flag = true;
				break;
			}
			else if (temp == 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << cnt;
		else
			cout << "IMPOSSIBLE";
		cout << "\n";
	}

	return 0;
}