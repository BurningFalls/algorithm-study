#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<int, int> mp;

int main() {
	FASTIO;
	int SUM;
	string s;
	getline(cin, s);
	cin >> SUM;
	s += ' ';
	int len = s.size();
	string sub = "";
	FOR(i, 0, len - 1) {
		if (s[i] == ' ') {
			int num = stoi(sub);
			mp[num] += 1;
			sub = "";
		}
		else
			sub += s[i];
	}
	vector<pii> v;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		v.push_back({ (*it).first, (*it).second });
	}
	int store = 0;
	int vlen = v.size();
	int ans = 0;
	FOR(i, 0, vlen - 1) {
		if (v[i].first * 2 == SUM) {
			if (v[i].second <= 1) continue;
			int tmp = v[i].second * (v[i].second - 1) / 2;
			ans++;
			cout << v[i].first << " " << v[i].first << "\n";
			break;
		}
		FOR(j, i + 1, vlen - 1) {
			if (v[i].first + v[j].first == SUM) {
				int tmp = v[i].second * v[j].second;
				ans++;
				cout << v[i].first << " " << v[j].first << "\n";
			}
		}
	}
	cout << ans;


	return 0;
}