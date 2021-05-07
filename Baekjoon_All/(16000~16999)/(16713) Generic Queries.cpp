#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[1000001];
ll result[1000001];

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	arr[0] = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		result[i] = result[i - 1] ^ arr[i];
	}
	ll ans = 0;
	FOR(i, 1, Q) {
		int s, e;
		cin >> s >> e;
		ans ^= (result[e] ^ result[s - 1]);
	}
	cout << ans;

	return 0;
}