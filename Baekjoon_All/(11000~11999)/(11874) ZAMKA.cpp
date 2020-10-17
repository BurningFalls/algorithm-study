#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int L, D, X;
	cin >> L >> D >> X;
	int minimum = D;
	int maximum = L;
	FOR(i, L, D) {
		string s = to_string(i);
		int sum = 0;
		FOR(j, 0, s.size() - 1)
			sum += (s[j] - '0');
		if (sum == X) {
			minimum = min(minimum, i);
			maximum = max(maximum, i);
		}
	}
	cout << minimum << "\n" << maximum;

	return 0;
}