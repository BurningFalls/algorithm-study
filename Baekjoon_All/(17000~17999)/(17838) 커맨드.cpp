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

bool Check(string s) {
	if (LEN(s) != 7) {
		return false;
	}
	if (!(s[0] == s[1] && s[1] == s[4])) {
		return false;
	}
	if (!(s[2] == s[3] && s[3] == s[5] && s[5] == s[6])) {
		return false;
	}
	if (s[0] == s[2]) {
		return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		cout << Check(s) << "\n";
	}


	return 0;
}