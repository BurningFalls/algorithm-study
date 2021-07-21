#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, S, D;
vector<int> v[100001];
int depth[100001];
bool visited[100001] = { 0, };

int Calc_Depth(int node) {
	int max_depth = 0;
	for (int next : v[node]) {
		if (visited[next]) continue;
		visited[next] = 1;
		max_depth = max(max_depth, Calc_Depth(next) + 1);
	}
	depth[node] = max_depth;
	return depth[node];
}

int DFS(int node) {
	if (depth[node] < D)
		return -2;
	int moving = 0;
	for (int next : v[node]) {
		if (visited[next]) continue;
		visited[next] = 1;
		moving += DFS(next) + 2;
	}
	return moving;
}

int main() {
	FASTIO;
	cin >> N >> S >> D;
	FOR(i, 1, N - 1) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	visited[S] = 1;
	Calc_Depth(S);
	if (depth[S] <= D) {
		cout << 0;
		return 0;
	}
	memset(visited, 0, sizeof(visited));
	visited[S] = 1;
	cout << DFS(S);

	return 0;
}