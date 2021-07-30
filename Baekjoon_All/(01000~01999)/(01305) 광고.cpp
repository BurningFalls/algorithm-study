#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int pi[1000001] = { 0, };

int main() {
	int L;
	cin >> L;
	string s;
	cin >> s;
	int j = 0;
	FOR(i, 1, L - 1) {
		while (s[i] != s[j] && j > 0)
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	cout << L - pi[L - 1];

	return 0;
}