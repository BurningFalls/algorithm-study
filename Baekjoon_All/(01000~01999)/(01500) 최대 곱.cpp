#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int S, K;
	cin >> S >> K;
	ll ans = 1;
	ll multi = S / K;
	ll cnt = S - (multi * K);
	FOR(i, 1, K - cnt)
		ans *= multi;
	FOR(i, 1, cnt)
		ans *= (multi + 1);
	cout << ans;


	return 0;
}