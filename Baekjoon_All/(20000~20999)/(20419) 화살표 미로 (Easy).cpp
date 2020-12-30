#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int R, C, K;
char arr[51][51];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
char dir[4] = { 'R', 'U', 'L', 'D' };
int rotate_L, rotate_R;
bool visited[51][51][151][151] = { 0, };

bool BFS() {
	queue<pair<pii, pii>> q;
	q.push({ {1, 1}, {K, K} });
	visited[1][1][K][K] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int L_cnt = q.front().second.first;
		int R_cnt = q.front().second.second;
		q.pop();
		if (y == R && x == C)
			return true;
		int idx = -1;
		FOR(i, 0, 3) {
			if (arr[y][x] == dir[i])
				idx = i;
		}
		FOR(i, 0, 3) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
			if (i == idx) {
				if (visited[ny][nx][L_cnt][R_cnt]) continue;
				visited[ny][nx][L_cnt][R_cnt] = 1;
				q.push({ {ny, nx}, {L_cnt, R_cnt} });
			}
			else {
				int use_L = ((i - idx) + 4) % 4;
				int use_R = ((idx - i) + 4) % 4;
				if (L_cnt >= use_L) {
					if (visited[ny][nx][L_cnt - use_L][R_cnt]) continue;
					visited[ny][nx][L_cnt - use_L][R_cnt] = 1;
					q.push({ {ny, nx}, {L_cnt - use_L, R_cnt} });
				}
				if (R_cnt >= use_R) {
					if (visited[ny][nx][L_cnt][R_cnt - use_R]) continue;
					visited[ny][nx][L_cnt][R_cnt - use_R] = 1;
					q.push({ {ny, nx}, {L_cnt, R_cnt - use_R} });
				}
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	cin >> R >> C >> K;
	rotate_L = K, rotate_R = K;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> arr[i][j];
		}
	}
	if (BFS())
		cout << "Yes";
	else
		cout << "No";

	return 0;
}