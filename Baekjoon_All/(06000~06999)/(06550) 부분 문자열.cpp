#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s, t;
	while (cin >> s >> t) {
		int slen = s.size();
		int tlen = t.size();
		int idx = 0;
		FOR(i, 0, tlen - 1) {
			if (t[i] == s[idx]) {
				idx++;
				if (idx == slen)
					break;
			}
		}
		cout << ((idx == slen) ? "Yes" : "No") << "\n";
	}

	return 0;
}