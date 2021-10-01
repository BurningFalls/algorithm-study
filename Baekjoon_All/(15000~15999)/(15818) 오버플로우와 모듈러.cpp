#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	ll N, M;
	cin >> N >> M;
	ll ans = 1;
	FOR(i, 1, N) {
		ll num;
		cin >> num;
		num = num % M;
		ans = (ans * num) % M;
	}
	cout << ans;

	return 0;
}