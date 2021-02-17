#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

map<string, int> mp;
vector<pair<string, int>> v;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	FASTIO;
	int K, L;
	cin >> K >> L;
	string s;
	FOR(i, 1, L) {
		cin >> s;
		mp[s] = i;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		v.push_back({ (*it).first, (*it).second });
	}
	sort(v.begin(), v.end(), compare);
	int len = v.size();
	FOR(i, 0, min(K - 1, len - 1)) {
		cout << v[i].first << "\n";
	}

	return 0;
}