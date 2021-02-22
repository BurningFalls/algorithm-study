#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

bool Check(string s) {
	int cnt[26] = { 0, };
	int len = s.size();
	FOR(i, 0, len - 1) {
		cnt[s[i] - 'A']++;
		if (cnt[s[i] - 'A'] == 3) {
			if (i == len - 1)
				return false;
			cnt[s[i] - 'A'] = 0;
			if (s[i + 1] != s[i])
				return false;
			i++;
		}
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s;	
		cin >> s;
		if (Check(s))
			cout << "OK";
		else
			cout << "FAKE";
		cout << "\n";
	}

	return 0;
}