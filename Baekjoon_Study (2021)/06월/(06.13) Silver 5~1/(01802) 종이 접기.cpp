#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string s;

bool Func(int start, int len) {
	bool sub_flag = true;
	FOR(i, 0, len / 2 - 1) {
		if (s[i] == s[len - i - 1])
			sub_flag = false;
	}
	if (sub_flag) {
		if (len == 3)
			return true;
		else
			return Func(0, len / 2) && Func(len / 2 + 1, len / 2);
	}
	else if (!sub_flag) {
		return false;
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		int len = s.size();
		if (len == 1) {
			cout << "YES" << "\n";
			continue;
		}
		bool flag = Func(0, len);
		cout << (flag ? "YES" : "NO") << "\n";
	}


	return 0;
}