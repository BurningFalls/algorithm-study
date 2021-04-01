#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	vector<int> v;
	FOR(i, 0, len - 1) {
		if (s[i] == 'H')
			v.push_back(1);
		else if (s[i] == 'C')
			v.push_back(12);
		else if (s[i] == 'O')
			v.push_back(16);
		else if (s[i] == '(')
			v.push_back(0);
		else if (s[i] == ')') {
			int tmp = 0;
			while (v.back() != 0) {
				tmp += v.back();
				v.pop_back();
			}
			v.pop_back();
			v.push_back(tmp);
		}
		else {
			v.back() += v.back() * (s[i] - '1');
		}
	}
	int ans = 0;
	for (int x : v) {
		ans += x;
	}
	cout << ans;

	return 0;
}