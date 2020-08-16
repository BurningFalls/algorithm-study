#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll arr[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		ll sum = 0;
		cin >> n;
		FOR(i, 1, n) {
			cin >> arr[i];
		}
		FOR(i, 1, n - 1) {
			if (arr[i] > arr[i + 1])
				sum += arr[i] - arr[i + 1];
		}
		cout << sum << "\n";
	}

	return 0;
}