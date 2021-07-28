#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int visited[101][101] = { 0, };
int dy1[3] = { 1, -1, -1 };
int dx1[3] = { 0, -1, 1 };
int dy2[3] = { 1, 1, -1 };
int dx2[3] = { -1, 1, 0 };
// 1 -> y°¡ Â¦¼ö, 2 -> y°¡ È¦¼ö
int ans = 0;

void Print() {
	FOR(i, 44, 56) {
		FOR(j, 44, 56) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void DFS(int y, int x) {
	if (visited[y][x] > N + 1) {
		visited[y][x] = 0;
		return;
	}
	if (y % 2 == 0) {
		FOR(i, 0, 2) {
			if (y == 50 && x == 50) {
				if (i == 1 || i == 2)
					continue;
			}
			int ny = y + dy1[i];
			int nx = x + dx1[i];
			if (visited[ny][nx]) {
				if (visited[y][x] != visited[ny][nx] + 1) {
					if (visited[y][x] == N + 1) {
						ans++;
						continue;
					}
				}
			}
			else {
				visited[ny][nx] = visited[y][x] + 1;
				DFS(ny, nx);
				visited[ny][nx] = 0;
			}
		}
	}
	else if (y % 2 == 1) {
		FOR(i, 0, 2) {
			int ny = y + dy2[i];
			int nx = x + dx2[i];
			if (visited[ny][nx]) {
				if (visited[y][x] != visited[ny][nx] + 1) {
					if (visited[y][x] == N + 1) {
						ans++;
						continue;
					}
				}
			}
			else {
				visited[ny][nx] = visited[y][x] + 1;
				DFS(ny, nx);
				visited[ny][nx] = 0;
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	visited[50][50] = 1;
	DFS(50, 50);
	cout << ans;

	return 0;
}