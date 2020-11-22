#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	string s;
	int cnt = 0;
	cin >> N;
	FOR(t, 1, N) {
		cin >> s;
		int len = s.size();
		vector<char> v;
		FOR(i, 0, len - 1) {
			if (v.empty()) {
				v.push_back(s[i]);
				continue;
			}
			if (v.back() == s[i])
				v.pop_back();
			else if (v.back() != s[i])
				v.push_back(s[i]);
		}
		if (v.size() == 0)
			cnt++;
	}
	cout << cnt;

	return 0;
}