#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int n;
int arr[502][502];
int visited[502][502] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int Func(int y, int x) {
	if (visited[y][x])
		return visited[y][x];
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
		if (arr[y][x] >= arr[ny][nx]) continue;
		visited[y][x] = max(visited[y][x], Func(ny, nx));
	}
	return visited[y][x] = visited[y][x] + 1;
}

int main() {
	FASTIO;
	int maximum = 0;
	cin >> n;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			if (visited[i][j]) continue;
			Func(i, j);
		}
	}
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			maximum = max(maximum, visited[i][j]);
		}
	}
	cout << maximum;

	return 0;
}