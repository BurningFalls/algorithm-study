#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int N;
vector<vector<int>> Map(4, vector<int>(4));
vector<vector<int>> choose(4, vector<int>(4, 0));
int bsum = 0;
int maxi = 0;

void DFS(int idx, int cnt) {
	if (idx == N * N || cnt == 4) {
		maxi = max(maxi, bsum);
		return;
	}
	int y = idx / N;
	int x = idx % N;
	if (choose[y][x]) {
		DFS(idx + 1, cnt);
		return;
	}
	// not choose
	DFS(idx + 1, cnt);
	// choose right
	if (x < N - 1 && !choose[y][x + 1]) {
		choose[y][x] = 1;
		choose[y][x + 1] = 1;
		bsum += Map[y][x] + Map[y][x + 1];
		DFS(idx + 1, cnt + 1);
		choose[y][x] = 0;
		choose[y][x + 1] = 0;
		bsum -= Map[y][x] + Map[y][x + 1];
	}
	// choose down
	if (y < N - 1 && !choose[y + 1][x]) {
		choose[y][x] = 1;
		choose[y + 1][x] = 1;
		bsum += Map[y][x] + Map[y + 1][x];
		DFS(idx + 1, cnt + 1);
		choose[y][x] = 0;
		choose[y + 1][x] = 0;
		bsum -= Map[y][x] + Map[y + 1][x];
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
		}
	}
	DFS(0, 0);
	cout << maxi;

	return 0;
}