#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		string s = to_string(N);
		int len = s.size();
		int ans = len + 1;
		FOR(i, 0, len - 1) {
			int x = s[i] - '0';
			if (x == 0)
				ans += 4;
			else if (x == 1)
				ans += 2;
			else
				ans += 3;
		}
		cout << ans << "\n";
	}

	return 0;
}