#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, M;
int arr[302][302];
int cnt[302][302] = { 0, };

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
			cnt[i][j] = INF;
		}
	}
	cnt[1][1] = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			int num = arr[i][j];
			FOR(k, j + 1, min(j + num, M))
				cnt[i][k] = min(cnt[i][k], cnt[i][j] + 1);
			FOR(k, i + 1, min(i + num, N))
				cnt[k][j] = min(cnt[k][j], cnt[i][j] + 1);
		}
	}
	cout << cnt[N][M];

	return 0;
}