#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[102];

int main() {
	FASTIO;
	int T;
	int idx = 1;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		FOR(i, 0, n) {
			cin >> arr[i];
		}
		cout << "Case " << idx << ": ";
		cout << n - 1 << " ";
		FOR(i, 0, n - 1) {
			cout << arr[i] * (n - i) << " ";
		}
		cout << "\n";
		idx++;
	}

	return 0;
}