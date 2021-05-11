#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int CH(string s) {
	int ans = 0;
	FOR(i, 0, 1) {
		int tmp;
		if (s[i] >= '0' && s[i] <= '9') {
			tmp = s[i] - '0';
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {
			tmp = s[i] - 'A' + 10;
		}
		if (i == 0) {
			ans += tmp * 16;
		}
		else if (i == 1) {
			ans += tmp;
		}
	}
	return ans;
}

int main() {
	FASTIO;
	string s;
	while (cin >> s) {
		int len = s.size();
		string tmp = "";
		FOR(i, 0, len - 1) {
			if (i % 2 == 0) {
				tmp += s[i];
			}
			else if (i % 2 == 1) {
				tmp += s[i];
				int num = CH(tmp);
				char x = num;
				cout << x;
				tmp = "";
			}
		}
		cout << "\n";
	}


	return 0;
}