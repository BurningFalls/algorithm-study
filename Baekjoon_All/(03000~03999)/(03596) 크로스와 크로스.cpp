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
	vector<int> dp(max(4, N + 1));
	dp[0] = 0;
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	FOR(i, 4, N) {
		set<int> s;
		FOR(j, 0, (i - 1) / 2) {
			int tmp = dp[i - 3 - j] ^ dp[max(0, j - 2)];
			s.insert(tmp);
		}
		int num = 0;
		for (int x : s) {
			if (x != num) {
				break;
			}
			num++;
		}
		dp[i] = num;
	}
	cout << (dp[N] ? 1 : 2);

	return 0;
}