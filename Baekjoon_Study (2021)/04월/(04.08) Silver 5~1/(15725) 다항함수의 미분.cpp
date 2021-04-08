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
	cin >> s;
	int len = s.size();
	bool xflag = false;
	int xpos = -1;
	FOR(i, 0, len - 1) {
		if (s[i] == 'x') {
			xpos = i;
			xflag = true;
			break;
		}
	}
	if (xflag) {
		if (xpos == 0)
			cout << 1;
		else if (xpos == 1 && s[0] == '-')
			cout << -1;
		else {
			FOR(i, 0, xpos - 1)
				cout << s[i];
		}
	}
	else if (!xflag) {
		cout << 0;
	}


	return 0;
}