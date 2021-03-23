#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int len = s.size();
		vector<char> v1, v2;
		if (len % 2 == 1) {
			s += s;
			len *= 2;
		}
		FOR(i, 0, len - 1) {
			if (i % 2 == 0)
				v1.push_back(s[i]);
			else if (i % 2 == 1)
				v2.push_back(s[i]);
		}
		for (char n : v1)
			cout << n;
		cout << "\n";
		for (char n : v2)
			cout << n;
		cout << "\n";
	}


	return 0;
}