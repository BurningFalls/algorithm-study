#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, int> mp;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		int slen;
		cin >> s;
		slen = s.size();
		string tmp = "";
		bool flag = false;
		FOR(i, 0, slen - 1) {
			if (s[i] == '.') {
				flag = true;
				continue;
			}
			if (flag)
				tmp += s[i];
		}
		if (mp.count(tmp))
			mp[tmp] += 1;
		else
			mp[tmp] = 1;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << (*it).first << " " << (*it).second << "\n";
	}


	return 0;
}