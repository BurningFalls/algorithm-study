#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
bool visited[201][201] = { 0, };
int ans[3];
int CNT = 0;

bool Check() {
	int a = ans[0];
	int b = ans[1];
	int c = ans[2];
	if (visited[a][b] || visited[b][a])
		return false;
	if (visited[b][c] || visited[c][b])
		return false;
	if (visited[a][c] || visited[c][a])
		return false;
	return true;
}

void DFS(int node, int cnt) {
	if (cnt == 3) {
		if (Check())
			CNT++;
		return;
	}
	FOR(i, node, N) {
		ans[cnt] = i;
		DFS(i + 1, cnt + 1);
	}
}

int main() {
	FASTIO;
	int M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
		visited[b][a] = 1;
	}
	DFS(1, 0);
	cout << CNT;

	return 0;
}