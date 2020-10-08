#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
bool visited[101][101] = { 0, };
int cnt[101] = { 0, };

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		visited[b][a] = 1;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (visited[i][k] == 0 || visited[k][j] == 0) continue;
				visited[i][j] = 1;
			}
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (visited[i][j] == 1) {
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	FOR(i, 1, N)
		cout << (N - 1) - cnt[i] << "\n";

	return 0;
}