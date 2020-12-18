#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<int, pii> mp;
vector<pair<pii, int>> v;

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.first == b.first.first)
		return a.first.second < b.first.second;
	return a.first.first > b.first.first;
}

int main() {
	FASTIO;
	int N, C;
	cin >> N >> C;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (!mp.count(num))
			mp.insert({ num, {1, i} });
		else {
			mp[num].first++;
		}
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		v.push_back({ {(*it).second.first, (*it).second.second}, (*it).first });
	}
	sort(v.begin(), v.end(), cmp);
	FOR(i, 0, v.size() - 1) {
		FOR(j, 1, v[i].first.first)
			cout << v[i].second << " ";
	}

	return 0;
}