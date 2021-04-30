#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	int a = 0, b = 0, c = 0;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		if (s == "1/4")
			a++;
		else if (s == "1/2")
			b++;
		else if (s == "3/4")
			c++;
	}
	int ans = 0;
	ans += c;
	a = max(a - c, 0);
	ans += b / 2;
	b = b % 2;
	if (b == 0) {
		if (a != 0)
			ans += (a - 1) / 4 + 1;
	}
	else if (b == 1) {
		ans += (1 + max(a - 2, 0) / 4);
	}
	cout << ans;

	return 0;
}