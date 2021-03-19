#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
bool arr[200001][2];
int visited[200001][2] = { 0, };

bool BFS() {
	queue<pii> q;
	q.push({ 1, 0 });
	visited[1][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int vis = visited[y][x];
		if (y > N)
			return 1;
		q.pop();
		if (arr[y + 1][x] && !visited[y + 1][x]) {
			visited[y + 1][x] = vis + 1;
			q.push({ y + 1, x });
		}
		if (y != 1 && arr[y - 1][x] && !visited[y - 1][x] && vis < y - 1) {
			visited[y - 1][x] = vis + 1;
			q.push({ y - 1, x });
		}
		if (arr[y + K][!x] && !visited[y + K][!x]) {
			visited[y + K][!x] = vis + 1;
			q.push({ y + K, !x });
		}
	}
	return 0;
}

int main() {
	FASTIO;
	cin >> N >> K;
	char x;
	FOR(i, 1, N) {
		cin >> x;
		arr[i][0] = x - '0';
	}
	FOR(i, 1, N) {
		cin >> x;
		arr[i][1] = x - '0';
	}
	FOR(i, N + 1, N + K) {
		FOR(j, 0, 1) {
			arr[i][j] = 1;
		}
	}
	cout << BFS();

	return 0;
}