#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100][100] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = -1;
	}
	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (arr[i][k] == 1 && arr[k][j] == 1)
					arr[i][j] = 1;
				if (arr[i][k] == -1 && arr[k][j] == -1)
					arr[i][j] = -1;
			}
		}
	}
	int plus_cnt, minus_cnt;
	int ans = 0;
	FOR(i, 1, N) {
		plus_cnt = 0;
		minus_cnt = 0;
		FOR(j, 1, N) {
			if (arr[i][j] == 1)
				plus_cnt++;
			else if (arr[i][j] == -1)
				minus_cnt++;
		}
		if (plus_cnt >= N / 2 + 1 || minus_cnt >= N / 2 + 1)
			ans++;
	}
	cout << ans;

	return 0;
}