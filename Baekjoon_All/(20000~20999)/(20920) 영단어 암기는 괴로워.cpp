#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, int> mp;
vector<pair<string, int>> v;

bool cmp(pair<string, int> x, pair<string, int> y) {
	int xlen = (x.first).size();
	int ylen = (y.first).size();
	if (x.second == y.second) {
		if (xlen == ylen)
			return (x.first) < (y.first);
		return xlen > ylen;
	}
	return x.second > y.second;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		int len = s.size();
		if (len < M) continue;
		if (mp.count(s))
			mp[s] += 1;
		else
			mp[s] = 1;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		v.push_back({ (*it).first, (*it).second });
	}
	sort(v.begin(), v.end(), cmp);
	for (pair<string, int> n : v) {
		cout << n.first << "\n";
	}

	return 0;
}