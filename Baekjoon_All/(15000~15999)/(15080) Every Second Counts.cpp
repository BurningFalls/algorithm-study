#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b, c, d, e, f;
	char x;
	int ans1, ans2;
	cin >> a >> x >> b >> x >> c;
	cin >> d >> x >> e >> x >> f;
	ans1 = 3600 * a + 60 * b + c;
	ans2 = 3600 * d + 60 * e + f;
	if (ans1 > ans2)
		cout << ans2 + 24 * 3600 - ans1;
	else
		cout << ans2 - ans1;

	return 0;
}