#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	while (true) {
		getline(cin, s);
		if (s == "***")
			break;
		int len = s.size();
		ROF(i, len - 1, 0)
			cout << s[i];
		cout << "\n";
	}


	return 0;
}