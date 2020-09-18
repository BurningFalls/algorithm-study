#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
int num[9];
int ans[9] = { 0, };

void DFS(int node, int cnt) {
	if (cnt == M + 1) {
		FOR(i, 1, M)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	int past = -1;
	FOR(i, node, N) {
		if (past == num[i]) continue;
		past = num[i];
		ans[cnt] = num[i];
		DFS(i, cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> num[i];
	sort(num + 1, num + N + 1);
	DFS(1, 1);

	return 0;
}