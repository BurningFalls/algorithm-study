#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<string> se;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		int len = s.size();
		string chs = s;
		chs += s;
		if (i == 1)
			se.insert(s);
		else {
			bool flag = true;
			FOR(i, 0, len - 1) {
				string tmp = chs.substr(i, len);
				if (se.count(tmp)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				se.insert(s);
			}
		}
	}
	int ans = se.size();
	cout << ans;


	return 0;
}