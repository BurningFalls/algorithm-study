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
#define MAX 1001

struct NODE {
	string s1;
	string s2;
	double l;
};

int N;
vector<int> cnt = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<NODE> v(MAX);
vector<double> p(MAX);

double Change(string s1, string s2) {
	double year = (s1[2] - '0') * 10 + (s1[3] - '0');
	double month = (s1[5] - '0') * 10 + (s1[6] - '0');
	double day = (s1[8] - '0') * 10 + (s1[9] - '0');
	day += year * 365;
	if (int(year) > 20) {
		day += 1;
	}
	FOR(i, 1, month - 1) {
		if (int(year) == 20 && int(i) == 2) {
			day += 1;
		}
		day += cnt[i];
	}
	double hour = (s2[0] - '0') * 10 + (s2[1] - '0');
	double minute = (s2[3] - '0') * 10 + (s2[4] - '0');
	double second = (s2[6] - '0') * 10 + (s2[7] - '0');
	day += hour / 24;
	day += minute / (24 * 60);
	day += second / (24 * 60 * 60);
	return day;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> v[i].s1 >> v[i].s2 >> v[i].l;
	}
	if (N == 0) {
		cout << 0;
		return 0;
	}
	double tn = Change(v[N].s1, v[N].s2);
	double up = 0, down = 0;
	FOR(i, 1, N) {
		double ti = Change(v[i].s1, v[i].s2);
		p[i] = max(pow(0.5, (tn - ti) / 365), pow(0.9, N - i));
		down += p[i];
		up += p[i] * v[i].l;
	}
	cout << round(up / down);

	return 0;
}