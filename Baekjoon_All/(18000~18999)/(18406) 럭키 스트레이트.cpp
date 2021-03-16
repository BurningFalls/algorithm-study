#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	int sum1 = 0, sum2 = 0;
	FOR(i, 0, len / 2 - 1) {
		sum1 += (s[i] - '0');
	}
	FOR(i, len / 2, len - 1) {
		sum2 += (s[i] - '0');
	}
	if (sum1 == sum2)
		cout << "LUCKY";
	else
		cout << "READY";


	return 0;
}