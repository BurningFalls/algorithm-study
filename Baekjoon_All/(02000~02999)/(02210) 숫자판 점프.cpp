#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[6][6];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans[6];
int CNT = 0;
bool visited[1000000] = { 0, };

void DFS(int y, int x, int cnt) {
	if (cnt == 6) {
		int temp = 0;
		FOR(i, 0, 5) {
			temp += ans[i] * pow(10, 5 - i);
		}
		if (!visited[temp]) {
			visited[temp] = 1;
			CNT++;
		}
		return;
	}
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || ny > 5 || nx < 1 || nx > 5) continue;
		ans[cnt] = arr[ny][nx];
		DFS(ny, nx, cnt + 1);
	}
}

int main() {
	FASTIO;
	FOR(i, 1, 5) {
		FOR(j, 1, 5) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, 5) {
		FOR(j, 1, 5) {
			ans[0] = arr[i][j];
			DFS(i, j, 1);
		}
	}
	cout << CNT;

	return 0;
}