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
	int S, T;
	cin >> S >> T;
	int ans = 0;
	FOR(a, 0, S) {
		FOR(b, 0, S - a) {
			FOR(c, 0, S - a - b) {
				if (a * b * c <= T)
					ans++;
			}
		}
	}
	cout << ans;


	return 0;
}