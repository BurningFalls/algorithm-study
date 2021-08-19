#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1000000001
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[200001];
int ans1[200001];
int ans2[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		ll k;
		int maxi1 = -INF;
		int maxi2 = -INF;
		cin >> n >> k;
		FOR(i, 1, n) {
			cin >> arr[i];
			maxi1 = max(maxi1, arr[i]);
		}
		FOR(i, 1, n) {
			ans1[i] = maxi1 - arr[i];
			maxi2 = max(maxi2, ans1[i]);
		}
		FOR(i, 1, n) {
			ans2[i] = maxi2 - ans1[i];
		}
		if (k % 2 == 1) {
			FOR(i, 1, n)
				cout << ans1[i] << " ";
		}
		else if (k % 2 == 0) {
			FOR(i, 1, n)
				cout << ans2[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}