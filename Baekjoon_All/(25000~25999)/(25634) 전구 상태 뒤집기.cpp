#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	vector<int> dp(N);
	int sum = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(i, 0, N - 1) {
		cin >> B[i];
		if (B[i] == 1) {
			sum += A[i];
		}
	}
	dp[0] = (B[0] == 1 ? -A[0] : A[0]);
	int maxi = dp[0];
	FOR(i, 1, N - 1) {
		int tmp = (B[i] == 1 ? -A[i] : A[i]);
		dp[i] = max(tmp, dp[i - 1] + tmp);
		maxi = max(maxi, dp[i]);
	}
	cout << sum + maxi;

	return 0;
}