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

vector<int> pi(5001);

void getPi(string x) {
	int j = 0;
	FOR(i, 1, LEN(x) - 1) {
		while (j > 0 && x[i] != x[j])
			j = pi[j - 1];
		if (x[i] == x[j])
			pi[i] = ++j;
	}
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	int maxi = 0;
	FOR(i, 0, LEN(s) - 1) {
		fill(ALL(pi), 0);
		string tmp = s.substr(i, LEN(s));
		getPi(tmp);
		FOR(j, 0, LEN(tmp) - 1) {
			maxi = max(maxi, pi[j]);
		}
	}
	P1(maxi);

	return 0;
}