#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, x, b, y, T;
	cin >> a >> x >> b >> y >> T;
	int ans1 = a, ans2 = b;
	if (T > 30)
		ans1 += (T - 30) * x * 21;
	if (T > 45)
		ans2 += (T - 45) * y * 21;
	cout << ans1 << " " << ans2;



	return 0;
}