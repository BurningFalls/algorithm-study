#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<string> SET, ANS;

int main() {
	FASTIO;
	string S, E, Q;
	cin >> S >> E >> Q;
	string Time, Name;
	int cnt = 0;
	while (cin >> Time >> Name) {
		if (Time <= S)
			SET.insert(Name);
		else if (E <= Time && Time <= Q) {
			if (SET.count(Name))
				ANS.insert(Name);
		}
	}
	int len = ANS.size();
	cout << len;


	return 0;
}