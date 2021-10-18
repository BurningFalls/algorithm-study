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
	set<string> se;
	cin >> s;
	deque<char> dq;
	FOR(i, 0, LEN(s) - 1) {
		dq.push_back(s[i]);
	}
	FOR(i, 0, LEN(s) - 1) {
		string tmp = "";
		FOR(j, 0, LEN(s) - 1) {
			tmp += dq[j];
		}
		se.insert(tmp);
		dq.push_back(dq.front());
		dq.pop_front();
	}
	cout << *(se.begin()) << "\n";
	auto it = se.end();
	it--;
	cout << (*it);

	return 0;
}