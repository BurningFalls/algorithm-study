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
		int a, b;
		cin >> a >> b;
		int ans = a + 1;
		if (a % 4 == 0) {
			if (b == 0)
				ans--;
			else if (b == a)
				ans++;
		}
		else if (a % 4 == 1) {
			if (b == a - 1)
				ans--;
			else if (b == 1)
				ans++;
		}
		else if (a % 4 == 2) {
			if (b == 1)
				ans--;
			else if (b == a + 1)
				ans++;
		}
		else if (a % 4 == 3) {
			if (b == a)
				ans--;
			else if (b == 0)
				ans++;
		}
		cout << ans << "\n";
	}



	return 0;
}