#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int M;
	cin >> M;
	bool flag = 0;
	long double ans = 1;
	FOR(i, 1, M) {
		long double a, b, c;
		cin >> a >> b >> c;
		ans = (b / a) * ans;
		if (c == 1)
			flag = !flag;
	}
	cout << flag << " " << ans;

	return 0;
}