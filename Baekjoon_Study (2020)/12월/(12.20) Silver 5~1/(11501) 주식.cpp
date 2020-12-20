#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[1000001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		ll ans = 0;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		int maximum = arr[N];
		ROF(i, N - 1, 1) {
			if (arr[i] < maximum)
				ans += maximum - arr[i];
			else
				maximum = arr[i];
		}
		cout << ans << "\n";
	}

	return 0;
}