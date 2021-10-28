#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int arr[5001];
int dp[5001][5001];

int DP(int left, int right) {
	int& ret = dp[left][right];
	if (left >= right) {
		return ret = 0;
	}
	if (ret != -1)
		return ret;
	ret = 0;
	if (arr[left] == arr[right]) {
		ret = DP(left + 1, right - 1);
	}
	else if (arr[left] != arr[right]) {
		ret = min(DP(left + 1, right), DP(left, right - 1)) + 1;
	}
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	cout << DP(1, N);

	return 0;
}