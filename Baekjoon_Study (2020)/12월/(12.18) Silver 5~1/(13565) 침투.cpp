#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int M, N;
char arr[1001][1001];
bool visited[1001][1001] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool flag;

void DFS(int y, int x) {
	if (y == M)
		flag = true;
	if (flag)
		return;
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || ny > M || nx < 1 || nx > N) continue;
		if (arr[ny][nx] == '1') continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		DFS(ny, nx);
	}
}

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, M) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	bool all_flag = false;
	FOR(i, 1, N) {
		if (arr[1][i] == '0') {
			flag = false;
			visited[1][i] = 1;
			DFS(1, i);
			if (flag) {
				all_flag = true;
				break;
			}
		}
	}
	if (all_flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}