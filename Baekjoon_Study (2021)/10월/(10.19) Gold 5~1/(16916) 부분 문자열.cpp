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

vector<int> pi(1000001);

void get_pi(string s) {
	int j = 0;
	FOR(i, 1, LEN(s) - 1) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
}

bool kmp(string s, string p) {
	get_pi(p);
	int j = 0;
	FOR(i, 0, LEN(s) - 1) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == LEN(p) - 1) {
				return true;
			}
			else {
				j++;
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	string S, P;
	cin >> S >> P;
	cout << kmp(S, P);

	return 0;
}