#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[2502] = { 0, };
string s1, s2;
int len1, len2;

bool Check(int pos) {
	FOR(i, 0, len2 - 1) {
		if (s1[pos - i] != s2[len2 - 1 - i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	getline(cin, s1);
	getline(cin, s2);
	len1 = s1.size();
	len2 = s2.size();
	if (len1 < len2)
		cout << 0;
	else {
		FOR(i, len2 - 1, len1 - 1) {
			if (Check(i))
				dp[(i + 1)] = dp[(i + 1) - len2] + 1;
			else
				dp[(i + 1)] = dp[i];
		}
		cout << dp[len1];
	}
	

	return 0;
}