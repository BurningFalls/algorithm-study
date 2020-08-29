#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

string a, b;
int dp[1001][1001] = { 0, };

void Find(int y, int x) {
	if (y == 0 || x == 0)
		return;
	if (b[y - 1] == a[x - 1]) {
		Find(y - 1, x - 1);
		cout << b[y - 1];
	}
	else {
		if (dp[y - 1][x] > dp[y][x - 1])
			Find(y - 1, x);
		else if (dp[y - 1][x] <= dp[y][x - 1])
			Find(y, x - 1);
	}
}

int main() {
	FASTIO;
	int Y, X;
	cin >> a >> b;
	Y = b.size(), X = a.size();
	FOR(i, 1, Y) {
		FOR(j, 1, X) {
			if (b[i - 1] == a[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else if (b[i - 1] != a[j - 1])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[Y][X] << "\n";
	Find(Y, X);

	return 0;
}