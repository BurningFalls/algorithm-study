
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int n;
string s;
int cnt[26] = { 0, };

bool Check() {
	FOR(i, 0, 25) {
		if (cnt[i] % n != 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		FOR(i, 0, 25)
			cnt[i] = 0;
		cin >> n;
		FOR(i, 1, n) {
			cin >> s;
			FOR(j, 0, s.size() - 1) {
				cnt[s[j] - 'a']++;
			}
		}
		if (Check())
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}
