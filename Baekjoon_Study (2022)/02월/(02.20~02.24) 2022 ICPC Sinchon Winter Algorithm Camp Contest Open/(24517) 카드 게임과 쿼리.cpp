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

vector<vector<int>> dp(56, vector<int>(1 << 10, -1));

int DP(int n, int k) {
	if (n <= 0) {
		return 0;
	}
	int& ret = dp[n][k];
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	FOR(i, 0, 9) {
		if (!(k & (1 << i))) continue;
		ret &= DP(n - (i + 1), k & ~(1 << i));
	}
	ret ^= 1;
	return ret;
}

int main() {
	FASTIO;
	int Q;
	cin >> Q;
	FOR(q, 1, Q) {
		int A, B, K;
		cin >> A >> B >> K;
		int sum = K * (K + 1) / 2;
		int cnt = (B - A) / sum;
		if ((B - A) % sum == 0) {
			cnt -= 1;
		}
		bool flag = DP(B - A - cnt * sum, (1 << K) - 1);
		if ((K * cnt) % 2 == 1) {
			flag = !flag;
		}
		cout << (flag ? "swoon" : "raararaara") << "\n";
	}

	return 0;
}