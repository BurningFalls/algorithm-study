#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll num[41];

int main() {
	FASTIO;
	ll N;
	ll ans = 0;
	num[0] = 1;
	FOR(i, 1, 40)
		num[i] = num[i - 1] * 3;
	cin >> N;
	int idx = 0;
	while (N != 0) {
		ans += (N % 2) * num[idx];
		idx++;
		N /= 2;
	}
	cout << ans;


	return 0;
}