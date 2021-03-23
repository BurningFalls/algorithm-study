#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	bool check[26];
	string s;
	while (true) {
		memset(check, 0, sizeof(check));
		getline(cin, s);
		if (s == "#")
			break;
		int len = s.size();
		FOR(i, 0, len - 1) {
			if (s[i] >= 'a' && s[i] <= 'z')
				check[s[i] - 'a'] = 1;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				check[s[i] - 'A'] = 1;
		}
		int cnt = 0;
		FOR(i, 0, 25)
			cnt += check[i];
		cout << cnt << "\n";
	}



	return 0;
}