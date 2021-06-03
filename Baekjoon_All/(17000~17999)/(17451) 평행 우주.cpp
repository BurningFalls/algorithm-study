#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[300001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	ll ans = arr[N];
	ROF(i, N - 1, 1) {
		ll tmp = ans / arr[i];
		if (ans % arr[i] != 0)
			tmp += 1;
		ans = arr[i] * tmp;
	}
	cout << ans;

	return 0;
}