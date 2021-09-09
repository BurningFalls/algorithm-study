#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<int> edge[200001];
bool visited[200001] = { 0, };

void DFS(int node) {
	visited[node] = 1;
	cout << node << " ";
	bool flag = false;
	for (int next : edge[node]) {
		if (visited[next]) continue;
		flag = true;
		DFS(next);
		cout << node << " ";
	}
	visited[node] = 0;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	FOR(i, 1, N) {
		sort(edge[i].begin(), edge[i].end());
	}
	DFS(1);

	return 0;
}