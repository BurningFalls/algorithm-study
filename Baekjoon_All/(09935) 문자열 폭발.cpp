#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	string s, bs;
	vector<char> v1;
	deque<pair<char, int>> v2;
	cin >> s;
	cin >> bs;
	int node = 0;
	FOR(i, 0, s.size() - 1) {
		if (s[i] != bs[node]) {
			if (s[i] != bs[0]) {
				while (!v2.empty()) {
					v1.push_back(v2.front().first);
					v2.pop_front();
				}
				v1.push_back(s[i]);
				node = 0;
			}
			else if (s[i] == bs[0]) {
				v2.push_back({ s[i], 0 });
				node = 1;
			}
		}
		else if (s[i] == bs[node]) {
			v2.push_back({ s[i], node });
			node++;
			if (node == bs.size()) {
				FOR(j, 0, node - 1)
					v2.pop_back();
				if (v2.empty())
					node = 0;
				else
					node = v2.back().second + 1;
			}
		}
	}
	if (v1.empty() && v2.empty())
		cout << "FRULA";
	else {
		int len1 = v1.size();
		int len2 = v2.size();
		FOR(i, 0, len1 - 1)
			cout << v1[i];
		FOR(i, 0, len2 - 1)
			cout << v2[i].first;
	}

	return 0;
}