#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	int mini_e = 100001;
	int maxi_s = 0;
	FOR(i, 1, N) {
		int s, e;
		cin >> s >> e;
		mini_e = min(mini_e, e);
		maxi_s = max(maxi_s, s);
	}
	int ans = maxi_s - mini_e;
	if (ans < 0)
		ans = 0;
	cout << ans;

	return 0;
}