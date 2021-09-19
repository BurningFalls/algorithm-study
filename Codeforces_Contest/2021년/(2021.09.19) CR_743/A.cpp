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
		int N;
		string s;
		cin >> N >> s;
		int ans = 0;
		FOR(i, 0, N - 1) {
			ans += s[i] - '0';
			if (s[i] != '0' && i != N - 1)
				ans++;
		}
		cout << ans << "\n";
	}



	return 0;
}