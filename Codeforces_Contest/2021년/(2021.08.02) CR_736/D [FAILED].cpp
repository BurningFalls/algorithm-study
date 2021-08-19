#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[200001];

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		if (N == 1) {
			cout << 1 << "\n";
			continue;
		}
		int max_length = 1;
		int length = 1;
		ll num = -1;
		FOR(i, 2, N) {
			ll tmp = abs(arr[i] - arr[i - 1]);
			if (num == -1) {
				if (tmp != 1) {
					num = tmp;
					length = 2;
				}
				else {
					num = -1;
					length = 1;
				}
			}
			else {
				ll gcd = GCD(num, tmp);
				if (gcd >= 2) {
					length++;
					num = min(num, gcd);
				}
				else {
					if (tmp != 1) {
						num = tmp;
						length = 2;
					}
					else {
						num = -1;
						length = 1;
					}
				}
			}
			max_length = max(max_length, length);
			cout << tmp << " " << num << " " << length << "\n";
		}
		cout << max_length << "\n";
	}


	return 0;
}