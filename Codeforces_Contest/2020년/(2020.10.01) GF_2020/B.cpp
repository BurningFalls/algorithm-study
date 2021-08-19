#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		FOR(i, 1, n)
			cin >> arr[i];
		int cnt = 0;
		FOR(i, 1, n - 1) {
			if (arr[i] != arr[i + 1])
				cnt++;
		}
		if (k == 1) {
			if (cnt == 0)
				cout << 1;
			else
				cout << -1;
		}
		else {
			if (cnt % (k - 1) == 0)
				cout << cnt / (k - 1);
			else
				cout << cnt / (k - 1) + 1;
		}
		cout << "\n";
	}

	return 0;
}