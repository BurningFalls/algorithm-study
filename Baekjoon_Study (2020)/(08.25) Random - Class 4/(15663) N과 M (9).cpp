#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
int num[9];
int ans[9] = { 0, };
bool visited[9] = { 0, };

void DFS(int cnt) {
	if (cnt == M + 1) {
		FOR(i, 1, M)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	int past = -1;
	FOR(i, 1, N) {
		if (visited[i]) continue;
		if (past == num[i]) continue;
		past = num[i];
		visited[i] = 1;
		ans[cnt] = num[i];
		DFS(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> num[i];
	sort(num + 1, num + N + 1);
	DFS(1);

	return 0;
}