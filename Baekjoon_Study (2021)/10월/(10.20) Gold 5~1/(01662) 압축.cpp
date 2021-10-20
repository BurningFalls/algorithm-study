#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	string s;
	cin >> s;
	vector<int> v;
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == '(' || s[i] == ')') continue;
		if (i == LEN(s) - 1 || s[i + 1] != '(') {
			s[i] = '1';
		}
	}
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == ')') {
			int cnt = 0;
			while (v.back() != -1) {
				cnt += v.back();
				v.pop_back();
			}
			v.pop_back();
			int multi = v.back();
			v.pop_back();
			v.push_back(cnt * multi);
		}
		else if (s[i] == '(') {
			v.push_back(-1);
		}
		else {
			v.push_back(s[i] - '0');
		}
	}
	int ans = 0;
	for (int x : v) {
		ans += x;
	}
	cout << ans;

	return 0;
}