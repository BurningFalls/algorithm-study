#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	int len = 0;
	bool flag = false;
	ll ans = 0;
	cin >> s;
	FOR(i, 0, s.size() - 1) {
		if (s[i] == '(') {
			len++;
			flag = true;
		}
		else if (s[i] == ')') {
			if (flag) {
				len--;
				ans += len;
			}
			else if (!flag) {
				len--;
				ans += 1;
			}
			flag = false;
		}
	}
	cout << ans;

	return 0;
}