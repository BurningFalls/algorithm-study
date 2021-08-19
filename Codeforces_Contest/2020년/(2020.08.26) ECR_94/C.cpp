#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

char func(int i, int x, string s) {
	int a = i - x;
	int b = i + x;
	if (a >= 0) {
		if (s[a] == '1')
			return '1';
	}
	if (b <= s.size() - 1) {
		if (s[b] == '1')
			return '1';
	}
	return '0';
}

char func2(int i, int x, string s) {
	int a = i - x;
	int b = i + x;
	if (a >= 0) {
		if (s[a] == '0')
			return '0';
	}
	if (b <= s.size() - 1) {
		if (s[b] == '0')
			return '0';
	}
	return '1';
}

int main() {
	FASTIO;
	int T;
	string s;
	cin >> T;
	while (T--) {
		int x;
		string ans;
		string ans2;
		cin >> s >> x;
		ans = "";
		ans2 = "";
		FOR(i, 0, s.size() - 1) {
			ans += func2(i, x, s);
		}
		FOR(i, 0, ans.size() - 1) {
			ans2 += func(i, x, ans);
		}
		if (s == ans2)
			cout << ans;
		else
			cout << -1;
		cout << "\n";
	}

	return 0;
}