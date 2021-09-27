#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[301][21];
int dp[21][301] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 0, M) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, M) {
		FOR(j, 1, N) {
			FOR(k, 0, j) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + arr[k][i]);
			}
		}
	}
	int maxi = 0;
	int max_idx = 0;
	FOR(i, 0, N) {
		if (maxi < dp[M][i]) {
			maxi = dp[M][i];
			max_idx = i;
		}
	}
	vector<int> ans_v;
	int node = max_idx;
	ROF(i, M - 1, 0) {
		FOR(j, 0, node) {
			if (dp[i][j] + arr[node - j][i + 1] == dp[i + 1][node]) {
				ans_v.push_back(node - j);
				node = j;
				break;
			}
		}
	}
	cout << maxi << "\n";
	ROF(i, LEN(ans_v) - 1, 0)
		cout << ans_v[i] << " ";


	return 0;
}