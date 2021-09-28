#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll W, H, N;
		cin >> W >> H >> N;
		ll tmp1 = 1;
		ll tmp2 = 1;
		while (W % 2 == 0) {
			W /= 2;
			tmp1 *= 2;
		}
		while (H % 2 == 0) {
			H /= 2;
			tmp2 *= 2;
		}
		cout << (tmp1 * tmp2 >= N ? "YES" : "NO") << "\n";
	}

	return 0;
}