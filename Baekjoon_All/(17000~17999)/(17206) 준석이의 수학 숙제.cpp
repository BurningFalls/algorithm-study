#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int dp[80001] = { 0, };

int main() {
	FASTIO;
	FOR(i, 1, 80000) {
		if (i % 3 == 0 || i % 7 == 0)
			dp[i] = dp[i - 1] + i;
		else
			dp[i] = dp[i - 1];
	}

	int T;
	cin >> T;
	FOR(i, 1, T)
		cin >> arr[i];
	FOR(i, 1, T) {
		cout << dp[arr[i]] << "\n";
	}


	return 0;
}