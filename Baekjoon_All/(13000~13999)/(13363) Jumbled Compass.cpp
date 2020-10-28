#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b;
	int ans1, ans2;
	cin >> a >> b;
	ans1 = (b - a + 360) % 360;
	ans2 = (a - b + 360) % 360;
	if (ans1 <= ans2)
		cout << ans1;
	else
		cout << -ans2;

	return 0;
}