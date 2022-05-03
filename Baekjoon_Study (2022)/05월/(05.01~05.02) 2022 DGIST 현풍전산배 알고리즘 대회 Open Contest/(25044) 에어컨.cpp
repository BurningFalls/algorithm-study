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

string Ch(int x) {
	string s = "";
	string hour = to_string(x / 60);
	string minute = to_string(x % 60);
	if (LEN(hour) == 1) {
		s += '0';
	}
	s += hour;
	s += ':';
	if (LEN(minute) == 1) {
		s += '0';
	}
	s += minute;
	return s;
}

pii Calc(pii x, int add) {
	return { (x.first + add) % 1440, (x.first + add >= 1440 ? x.second + 1 : x.second)};
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	pii timing = { 900, 0 };
	int add[3] = { 180, 180, 1080 + K };
	int cnt = 0;
	vector<int> v;
	int idx = 0;
	while (timing.second <= N) {
		if (timing.second == N) {
			v.push_back(timing.first);
		}
		if (idx == 2) {
			timing = Calc(timing, add[idx]);
			idx = 0;
		}
		else {
			timing = Calc(timing, add[idx]);
			idx += 1;
		}
	}
	cout << LEN(v) << "\n";
	for(int x : v) {
		cout << Ch(x) << "\n";
	}


	return 0;
}