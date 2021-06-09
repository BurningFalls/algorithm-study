#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int cnt = 0;
	FOR(i, 1, 6) {
		char x;
		cin >> x;
		if (x == 'W')
			cnt++;
	}
	int ans = -1;
	if (cnt >= 5 && cnt <= 6)
		ans = 1;
	else if (cnt >= 3 && cnt <= 4)
		ans = 2;
	else if (cnt >= 1 && cnt <= 2)
		ans = 3;
	else
		ans = -1;
	cout << ans;

	return 0;
}