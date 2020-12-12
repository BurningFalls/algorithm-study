#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[11][11];
bool visited[11][11] = { 0, };
int ans[3];
int dy[12] = { -2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2 };
int dx[12] = { 0, -1, 0, 1, -2, -1, 1, 2, -1, 0, 1, 0 };
int minimum = 3001;
int dy2[4] = { -1, 1, 0, 0 };
int dx2[4] = { 0, 0, -1, 1 };

bool Check(int y, int x) {
	FOR(i, 0, 11) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N - 2 || nx > N - 2) continue;
		if (visited[ny][nx])
			return false;
	}
	return true;
}

void DFS(int node, int cnt) {
	if (cnt == 3) {
		int sum = 0;
		FOR(i, 0, 2) {
			int y = ans[i] / (N - 2) + 1;
			int x = ans[i] % (N - 2) + 1;
			sum += arr[y][x];
			FOR(j, 0, 3) {
				int ny = y + dy2[j];
				int nx = x + dx2[j];
				sum += arr[ny][nx];
			}
		}
		minimum = min(minimum, sum);
		return;
	}
	FOR(i, node, (N - 2) * (N - 2) - 1) {
		int y = i / (N - 2) + 1;
		int x = i % (N - 2) + 1;
		if (!Check(y, x)) continue;
		visited[y][x] = 1;
		ans[cnt] = i;
		DFS(i + 1, cnt + 1);
		visited[y][x] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> arr[i][j];
		}
	}
	DFS(0, 0);
	cout << minimum;

	return 0;
}