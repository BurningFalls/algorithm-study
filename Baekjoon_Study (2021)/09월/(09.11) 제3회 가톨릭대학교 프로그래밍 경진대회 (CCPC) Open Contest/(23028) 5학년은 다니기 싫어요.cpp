#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int dp[151][151];
int arr[10][2];

int DP(int a, int b, int idx) {
	if (idx >= 10)
		return 20;
	if (a >= 66 && b >= 130)
		return 0;
	int ret = dp[a][b];
	if (ret != -1)
		return ret;
	ret = 20;
	FOR(i, 0, arr[idx][0]) {
		int j = min(arr[idx][1], 6 - i);
		ret = min(ret, DP(a + 3 * i, b + 3 * i + 3 * j, idx + 1) + 1);
	}
	return ret;
}

int main() {
	FASTIO;
	MEMSET(dp, -1);
	int N, A, B;
	cin >> N >> A >> B;
	N = 8 - N;
	FOR(i, 0, 9) {
		FOR(j, 0, 1) {
			cin >> arr[i][j];
		}
	}
	cout << (DP(A, B, 0) <= N ? "Nice" : "Nae ga wae");

	return 0;
}