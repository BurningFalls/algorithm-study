#include <bits/stdc++.h>
#include <regex>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	regex r(R"(^[A-F]?A+F+C+[A-F]?$)");
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		cout << (regex_match(s, r) ? "Infected!" : "Good") << "\n";
	}

	return 0;
}