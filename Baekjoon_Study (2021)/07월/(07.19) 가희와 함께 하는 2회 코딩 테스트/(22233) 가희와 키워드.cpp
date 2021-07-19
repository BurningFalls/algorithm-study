#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

unordered_map<string, int> mp;

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	int cnt = N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		int slen = s.size();
		if (slen > 10) continue;
		mp.insert({ s, 1 });
	}
	FOR(i, 1, M) {
		string s;
		cin >> s;
		s += ',';
		int len = s.size();
		string tmp = "";
		FOR(j, 0, len - 1) {
			if (s[j] == ',') {
				if (mp.count(tmp) && mp[tmp] == 1) {
					mp[tmp] = 0;
					cnt--;
				}
				tmp = "";
			}
			else
				tmp += s[j];
		}
		cout << cnt << "\n";
	}


	return 0;
}