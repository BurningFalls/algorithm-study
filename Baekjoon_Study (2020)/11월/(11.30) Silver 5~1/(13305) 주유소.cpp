#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll len[100001];
ll cost[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N - 1)
		cin >> len[i];
	FOR(i, 1, N) {
		cin >> cost[i];
		if (i != 1) {
			if (cost[i - 1] < cost[i])
				cost[i] = cost[i - 1];
		}
	}
	ll ans = 0;
	FOR(i, 1, N - 1) {
		ans += len[i] * cost[i];
	}
	cout << ans;


	return 0;
}