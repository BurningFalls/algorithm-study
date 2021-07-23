#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s;
		int cnt[26] = { 0, };
		cin >> s;
		int len = s.size();
		FOR(i, 0, len - 1) {
			cnt[s[i] - 'a']++;
		}
		int one_cnt = 0;
		int two_cnt = 0;
		FOR(i, 0, 25) {
			if (cnt[i] == 1)
				one_cnt++;
			else if (cnt[i] >= 2)
				two_cnt++;
		}
		cout << two_cnt + one_cnt / 2 << "\n";
	}


	return 0;
}