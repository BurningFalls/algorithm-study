#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	string s;
	cin >> s;
	vector<int> v(LEN(s), -1);
	vector<int> tmp;
	int idx = -1;
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == '(') {
			idx++;
			v[i] = idx;
			tmp.push_back(idx);
		}
		else if (s[i] == ')') {
			v[i] = tmp.back();
			tmp.pop_back();
		}
	}
	set<string> ans;
	FOR(i, 0, (1 << (idx + 1)) - 2) {
		string tmp = "";
		FOR(j, 0, LEN(s) - 1) {
			if (v[j] == -1 || (i & (1 << v[j]))) {
				tmp += s[j];
			}
		}
		ans.insert(tmp);
	}
	for (auto x : ans) {
		cout << x << "\n";
	}

	return 0;
}