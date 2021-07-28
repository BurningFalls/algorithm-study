#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string S;
	cin >> S;
	int len = S.size();
	FOR(i, 0, len - 1) {
		int tmp = S[i];
		string s = to_string(tmp);
		int slen = s.size();
		int sum = 0;
		FOR(j, 0, slen - 1) {
			sum += s[j] - '0';
		}
		FOR(j, 1, sum)
			cout << S[i];
		cout << "\n";
	}


	return 0;
}