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
	int cnt = 0;
	FOR(i, 0, len - 1) {
		if (s[i] == 'Y') {
			cnt++;
			for (int j = i; j <= len - 1; j += (i + 1)) {
				if (s[j] == 'Y')
					s[j] = 'N';
				else if (s[j] == 'N')
					s[j] = 'Y';
			}
		}
	}
	bool flag = true;
	FOR(i, 0, len - 1) {
		if (s[i] == 'Y') {
			flag = false;
			break;
		}
	}
	cout << (flag ? cnt : -1);

	return 0;
}