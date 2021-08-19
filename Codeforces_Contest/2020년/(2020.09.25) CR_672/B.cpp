#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[100001];

int main() {
	FASTIO;
	int T;
	ll Cnt[33];
	cin >> T;
	while (T--) {
		int n;
		int num;
		ll ans = 0;
		FOR(i, 0, 32)
			Cnt[i] = 0;
		cin >> n;
		FOR(i, 1, n) {
			cin >> arr[i];
		}
		FOR(i, 1, n) {
			int temp = arr[i];
			ll cnt = 0;
			while (temp != 1) {
				temp /= 2;
				cnt++;
			}
			Cnt[cnt]++;
		}
		FOR(i, 0, 32) {
			if (Cnt[i] == 0 || Cnt[i] == 1) continue;
			ans += ((Cnt[i] - 1) * Cnt[i] / 2);
		}
		cout << ans << "\n";
	}

	return 0;
}