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
	int N;
	string s;
	cin >> N;
	cin.ignore();
	getline(cin, s);
	s += ' ';
	string tmp = "";
	set<string> se;
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == ' ') {
			if (LEN(tmp) >= 6) {
				string t = "";
				FOR(j, LEN(tmp) - 6, LEN(tmp) - 1) {
					t += tmp[j];
				}
				if (t == "Cheese") {
					se.insert(tmp);
				}
			}
			tmp = "";
		}
		else {
			tmp += s[i];
		}
	}
	cout << (LEN(se) >= 4 ? "yummy" : "sad");

	return 0;
}