#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];
int dp[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int maximum;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		dp[1] = arr[1];
		maximum = dp[1];
		FOR(i, 2, N) {
			dp[i] = max(arr[i], dp[i - 1] + arr[i]);
			maximum = max(maximum, dp[i]);
		}
		cout << maximum << "\n";
	}

	return 0;
}