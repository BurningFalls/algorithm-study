#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int A[2001];
int B[2001];
int dp[2001][2001];

int DP(int left, int right) {
	if (left >= N || right >= N)
		return 0;
	int& ret = dp[left][right];
	if (ret != -1)
		return ret;
	ret = 0;
	if (A[left] > B[right])
		ret += DP(left, right + 1) + B[right];
	else
		ret += max(DP(left + 1, right), DP(left + 1, right + 1));
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	FOR(i, 0, N - 1)
		cin >> A[i];
	FOR(i, 0, N - 1)
		cin >> B[i];
	cout << DP(0, 0);

	return 0;
}