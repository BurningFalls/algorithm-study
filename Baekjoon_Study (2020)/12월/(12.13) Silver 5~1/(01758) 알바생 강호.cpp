#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[100001];

int main() {
	FASTIO;
	int N;
	ll ans = 0;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1, greater<int>());
	FOR(i, 1, N) {
		ll temp = arr[i] - (i - 1);
		if (temp < 0)
			temp = 0;
		ans += temp;
	}
	cout << ans;

	return 0;
}