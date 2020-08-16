#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int sum, dif;
	int ans1, ans2;
	cin >> sum >> dif;
	ans1 = (sum + dif) / 2;
	ans2 = (sum - dif) / 2;
	if (ans1 < 0 || ans2 < 0 || (sum + dif) % 2 != 0 || (sum - dif) % 2 != 0)
		cout << -1;
	else
		cout << ans1 << " " << ans2;

	return 0;
}