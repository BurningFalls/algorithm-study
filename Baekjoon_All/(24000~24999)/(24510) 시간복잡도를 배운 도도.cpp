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

int Find(string s, string goal) {
	int cnt = 0;
	FOR(i, 0, LEN(s) - LEN(goal)) {
		bool flag = true;
		FOR(j, i, i + LEN(goal) - 1) {
			if (s[j] != goal[j - i]) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
	}
	return cnt;
}

int main() {
	FASTIO;
	int C;
	cin >> C;
	int maxi = 0;
	FOR(i, 1, C) {
		string s;
		cin >> s;
		int ans = 0;
		ans += Find(s, "for");
		ans += Find(s, "while");
		maxi = max(maxi, ans);
	}
	cout << maxi;

	return 0;
}