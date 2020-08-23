#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	bool S[21] = { 0, };
	int M;
	string s;
	int x;
	cin >> M;
	FOR(i, 1, M) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			S[x] = 1;
		}
		else if (s == "remove") {
			cin >> x;
			S[x] = 0;
		}
		else if (s == "check") {
			cin >> x;
			cout << S[x] << "\n";
		}
		else if (s == "toggle") {
			cin >> x;
			S[x] = !S[x];
		}
		else if (s == "all") {
			FOR(j, 1, 20)
				S[j] = 1;
		}
		else if (s == "empty") {
			FOR(j, 1, 20)
				S[j] = 0;
		}
	}

	return 0;
}