#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> dp(6001, 0);
	int sum = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i];
		A[i] %= 7;
		sum += A[i];
	}

	dp[0] = 1;
	FOR(i, 0, N - 1) {
		ROF(j, sum, A[i]) {
			dp[j] |= dp[j - A[i]];
		}
	}
	bool flag = false;
	for (int i = 4; i <= sum; i += 7) {
		flag |= dp[i];
	}
	cout << (flag ? "YES" : "NO");

	return 0;
}