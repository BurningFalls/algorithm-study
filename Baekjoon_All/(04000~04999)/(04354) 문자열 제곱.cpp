#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int pi[1000001];

int main() {
	FASTIO;
	while (true) {
		memset(pi, 0, sizeof(pi));
		string s;
		cin >> s;
		if (s == ".")
			break;
		int len = s.size();
		int j = 0;
		FOR(i, 1, len - 1) {
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j])
				pi[i] = ++j;
		}
		if (len % (len - pi[len - 1]))
			cout << 1;
		else
			cout << len / (len - pi[len - 1]);
		cout << "\n";
	}

	return 0;
}