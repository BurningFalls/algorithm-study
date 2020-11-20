#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N;
int arr[11][11];
int sum = 0;
int ans = INF;
bool visited[11] = { 0, };

void DFS(int node, int cnt, int start) {
	if (cnt == N) {
		if (arr[node][start] != 0)
			ans = min(ans, sum + arr[node][start]);
		return;
	}
	FOR(i, 1, N) {
		if (arr[node][i] == 0) continue;
		if (visited[i]) continue;
		visited[i] = 1;
		sum += arr[node][i];
		DFS(i, cnt + 1, start);
		sum -= arr[node][i];
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) FOR(j, 1, N)
		cin >> arr[i][j];
	FOR(i, 1, N) {
		visited[i] = 1;
		DFS(i, 1, i);
		visited[i] = 0;
	}
	cout << ans;

	return 0;
}