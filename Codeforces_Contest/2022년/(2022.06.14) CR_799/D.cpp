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
#define INF (int)2e9
#define LINF (ll)1e18

string Ch(int x) {
	int hour = x / 60;
	int minute = x % 60;
	string s = "";
	if (hour < 10) {
		s += '0';
	}
	s += to_string(hour);
	s += ':';
	if (minute < 10) {
		s += '0';
	}
	s += to_string(minute);
	return s;
}

bool Check_PD(string s) {
	FOR(i, 0, LEN(s) / 2 - 1) {
		if (s[i] != s[LEN(s) - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s;
		int x;
		cin >> s >> x;
		int start = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
		int tim = (start + x) % 1440;
		int ans = Check_PD(s);
		while (tim != start) {
			ans += Check_PD(Ch(tim));
			tim = (tim + x) % 1440;
		}
		cout << ans << "\n";
	}

	return 0;
}