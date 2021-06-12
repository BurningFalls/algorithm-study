#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _INF {
	int start;
	int end;
	int people;
} INF;

INF arr[26];
int dp[26];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int s, e, p;
		cin >> s >> e >> p;
		arr[i] = { s, e, p };
	}
	dp[0] = 0;
	dp[1] = arr[1].people;
	FOR(i, 2, N) {
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i].people);
	}
	cout << dp[N];

	return 0;
}