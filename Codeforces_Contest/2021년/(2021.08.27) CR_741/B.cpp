#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[12] = { "22", "25", "27", "32", "33", "35", "52", "55", "57", "72", "75", "77" };

bool Find(string s, string sub) {
	int slen = s.size();
	int idx = 0;
	FOR(i, 0, slen - 1) {
		if (s[i] == sub[idx]) {
			idx++;
			if (idx == 2)
				return true;
		}
	}
	return false;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int K;
		string s;
		cin >> K;
		cin >> s;
		bool flag = false;
		FOR(i, 0, K - 1) {
			if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7') continue;
			cout << 1 << "\n" << s[i] << "\n";
			flag = true;
			break;
		}
		if (flag) continue;
		FOR(i, 0, 11) {
			if (Find(s, arr[i])) {
				cout << 2 << "\n" << arr[i] << "\n";
				break;
			}
		}
	}


	return 0;
}