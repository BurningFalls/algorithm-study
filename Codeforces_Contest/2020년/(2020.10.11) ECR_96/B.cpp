#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		FOR(i, 1, N)
			cin >> arr[i];
		sort(arr + 1, arr + N + 1, greater<int>());
		ll ans = 0;
		FOR(i, 1, K + 1) {
			ans += arr[i];
		}
		cout << ans << "\n";
	}

	return 0;
}