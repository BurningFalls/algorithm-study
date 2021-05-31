#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2500000001LL

ll arr[250001];
ll dp[250001];

int main() {
	FASTIO;
	while (true) {
		memset(dp, 0, sizeof(dp));
		int N;
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		signed long long int maxi = -INF;
		FOR(i, 1, N) {
			dp[i] = max(arr[i], dp[i - 1] + arr[i]);
			maxi = max(maxi, dp[i]);
		}
		cout << maxi << "\n";
	}


	return 0;
}