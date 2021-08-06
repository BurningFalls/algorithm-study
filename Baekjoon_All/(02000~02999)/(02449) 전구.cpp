#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int arr[201];
int dp[201][201];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 1, N)
		dp[i][i] = 0;
	FOR(i, 1, N - 1) {
		dp[i][i + 1] = (arr[i] != arr[i + 1]);
	}
	FOR(len, 3, N) {
		FOR(start, 1, N + 1 - len) {
			int end = start + len - 1;
			int mini = INF;
			FOR(k, start, end - 1) {
				int tmp = (dp[start][k] + dp[k + 1][end]) + (arr[start] != arr[k + 1]);
				mini = min(mini, tmp);
			}
			dp[start][end] = mini;
		}
	}
	cout << dp[1][N];


	return 0;
}