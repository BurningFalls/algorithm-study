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

int Change(string s) {
	int hour = (s[0] - '0') * 10 + (s[1] - '0');
	int minute = (s[3] - '0') * 10 + (s[4] - '0');
	int second = (s[6] - '0') * 10 + (s[7] - '0');
	return 60 * 60 * hour + 60 * minute + second;
}

int main() {
	FASTIO;
	string s1, s2;
	cin >> s1 >> s2;
	int t1 = Change(s1);
	int t2 = Change(s2);
	int tmp = 24 * 60 * 60;
	int result = (t2 + tmp - t1) % tmp;
	if (result == 0) {
		result = tmp;
	}
	int hour = result / (60 * 60);
	result -= (60 * 60) * hour;
	int minute = result / 60;
	result -= 60 * minute;
	int second = result;

	if (hour < 10) {
		cout << 0;
	}
	cout << hour << ':';
	if (minute < 10) {
		cout << 0;
	}
	cout << minute << ':';
	if (second < 10) {
		cout << 0;
	}
	cout << second;

	return 0;
}