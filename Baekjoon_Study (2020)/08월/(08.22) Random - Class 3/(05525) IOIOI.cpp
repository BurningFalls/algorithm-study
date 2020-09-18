#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int dp[1000001] = { 0, };

int main() {
	FASTIO;
	int N, M;
	string s;
	int cnt = 0;
	cin >> N >> M;
	cin >> s;
	FOR(i, 2, M - 1) {
		if (s[i - 2] == 'I' && s[i - 1] == 'O' && s[i] == 'I') {
			dp[i] = dp[i - 2] + 2;
			i++;
		}
	}
	FOR(i, 0, M - 1) {
		if (dp[i] >= 2 * N)
			cnt++;
	}
	cout << cnt;

	return 0;
}