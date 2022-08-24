#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	FOR(i, 1, T) {
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < LEN(s) - 1 - i; i++) {
			if (s[i] != s[LEN(s) - 1 - i]) break;
			cnt++;
		}
		cout << (cnt == LEN(s) / 2) << " " << cnt + 1 << "\n";
	}

	return 0;
}