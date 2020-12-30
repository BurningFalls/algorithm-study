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
	string s;
	cin >> N;
	FOR(i, 1, N) {
		cin >> s;
		if (mp.count(s))
			mp[s]++;
		else
			mp.insert({ s, 1 });
	}
	FOR(i, 1, N - 1) {
		cin >> s;
		mp[s]--;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if ((*it).second != 0) {
			cout << (*it).first;
			break;
		}
	}

	return 0;
}