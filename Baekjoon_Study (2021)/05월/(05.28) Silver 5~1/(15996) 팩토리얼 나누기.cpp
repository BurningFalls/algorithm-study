#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll N, A;
	int ans = 0;
	cin >> N >> A;
	ll tmp = A;
	while (tmp <= N) {
		ans += N / tmp;
		tmp *= A;
	}
	cout << ans;

	return 0;
}