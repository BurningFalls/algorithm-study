#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[300001];
// first: maximum interval
// second: end index
pair<int, int> interval[300001];
int ans[300001];

int main() {
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		FOR(i, 1, 300000)
			interval[i] = { 0,0 };
		FOR(i, 1, n)
			cin >> arr[i];
		FOR(i, 1, n) {
			interval[arr[i]].first = max(interval[arr[i]].first, i - interval[arr[i]].second);
			interval[arr[i]].second = i;
		}
		FOR(i, 1, 300000) {
			if (interval[arr[i]].first != 0) {
				interval[arr[i]].first = max(interval[arr[i]].first, (n + 1) - interval[arr[i]].second);
			}
		}
		FOR(i, 1, n) {
			ans[i] = 300001;
		}
		FOR(i, 1, 300000) {
			if (interval[arr[i]].first != 0) {
				ans[interval[i].first] = min(ans[interval[i].first], i);
			}
		}
		FOR(i, 2, n) {
			ans[i] = min(ans[i - 1], ans[i]);
		}
		FOR(i, 1, n) {
			if (ans[i] == 300001)
				cout << -1;
			else
				cout << ans[i];
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}