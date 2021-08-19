#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		int minimum = 10001;
		int cnt = 0;
		int idx = 0;
		cin >> n >> k;
		FOR(i, 1, n) {
			cin >> arr[i];
			if (minimum > arr[i]) {
				minimum = arr[i];
				idx = i;
			}
		}
		FOR(i, 1, n) {
			if (i == idx) continue;
			cnt += (k - arr[i]) / minimum;
		}
		cout << cnt << "\n";
	}

	return 0;
}