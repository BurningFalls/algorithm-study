#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		int prev = num;
		int ans = 0;
		while (true) {
			cin >> num;
			if (num == 0)
				break;
			ans += max(0, num - prev * 2);
			prev = num;
		}
		cout << ans << "\n";
	}


	return 0;
}