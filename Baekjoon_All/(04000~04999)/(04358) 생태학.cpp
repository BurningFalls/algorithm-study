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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

map<string, double> mp;

int main() {
	FASTIO;
	string s;
	int cnt = 0;
	while (getline(cin, s)) {
		if (!mp.count(s))
			mp[s] = 0;
		mp[s] += 1;
		cnt += 1;
	}
	cout << fixed << setprecision(4);
	for (auto it = mp.begin(); it != mp.end(); it++) {
		P2((*it).first, (*it).second * 100 / cnt);
	}


	return 0;
}