#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MOD 1000000007

bool Map[1003][1003];
ll arr[1003][1003] = { 0, };

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			Map[i][j] = 1;
		}
	}
	Map[1][1] = 0;
	FOR(i, 1, K) {
		int a, b;
		cin >> a >> b;
		Map[a][b] = 0;
	}
	arr[1][1] = 1;
	FOR(i, 1, M) {
		FOR(j, 1, N) {
			if (Map[j][i] == 0) continue;
			if (i % 2 == 0)
				arr[j][i] = (arr[j - 1][i] + arr[j][i - 1] + arr[j + 1][i - 1]) % MOD;
			else if (i % 2 == 1)
				arr[j][i] = (arr[j - 1][i] + arr[j][i - 1] + arr[j - 1][i - 1]) % MOD;
		}
	}
	cout << arr[N][M];


	return 0;
}