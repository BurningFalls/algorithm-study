#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
double Pb[4];
bool visited[31][31] = { 0, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
// E, W, S, W
double ans = 0;

void DFS(int y, int x, int cnt, double pb) {
	if (cnt == N) {
		ans += pb;
		return;
	}
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		DFS(ny, nx, cnt + 1, pb * Pb[i]);
		visited[ny][nx] = 0;
	}
}

int main() {
	FASTIO;
	double num;
	cin >> N;
	FOR(i, 0, 3) {
		cin >> num;
		Pb[i] = num * 0.01;
	}
	visited[15][15] = 1;
	DFS(15, 15, 0, 1);
	cout << fixed << setprecision(9);
	cout << ans;

	return 0;
}