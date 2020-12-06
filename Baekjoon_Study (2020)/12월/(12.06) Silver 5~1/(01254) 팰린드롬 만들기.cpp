#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s, rs;
	cin >> s;
	rs = s;
	reverse(rs.begin(), rs.end());
	int len = s.size();
	FOR(i, 0, len - 1) {
		bool flag = true;
		FOR(j, 0, len - 1 - i) {
			if (s[i + j] != rs[j])
				flag = false;
		}
		if (flag) {
			cout << len + i;
			break;
		}
	}

	return 0;
}