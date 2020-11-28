#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[8];
int ans[8] = { 0, };

void DFS(int node, int cnt) {
	if (cnt == M) {
		FOR(i, 0, M - 1)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	FOR(i, 1, N) {
		if (ans[cnt] == arr[i]) continue;
		ans[cnt] = arr[i];
		DFS(i, cnt + 1);
	}
	ans[cnt] = 0;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	DFS(1, 0);

	return 0;
}