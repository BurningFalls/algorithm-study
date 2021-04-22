#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int trees[51];

int main() {
	FASTIO;
	int N, C, W;
	cin >> N >> C >> W;
	int maxi = 0;
	FOR(i, 1, N) {
		cin >> trees[i];
		maxi = max(maxi, trees[i]);
	}
	ll ans = 0;
	int num = 0;
	FOR(i, 1, maxi) {
		ll sum = 0;
		FOR(j, 1, N) {
			if (trees[j] < i) continue;
			int cnt = 0;
			int div = 0;
			cnt = trees[j] / i;
			if (trees[j] % i == 0)
				div += trees[j] / i - 1;
			else
				div += trees[j] / i;
			sum += max(cnt * i * W - div * C, 0);
		}
		ans = max(ans, sum);
	}
	cout << ans;


	return 0;
}