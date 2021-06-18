#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	if (a == b) {
		if (n == 2 && w == a + b)
			cout << 1 << " " << 1;
		else
			cout << -1;
		return 0;
	}
	int tmp1 = w - a * n;
	int tmp2 = w - b * n;
	
	if (tmp1 % abs(b - a) != 0 || tmp2 % abs(a - b) != 0) {
		cout << -1;
		return 0;
	}
	int y = tmp1 / (b - a);
	int x = tmp2 / (a - b);
	if (y <= 0 || x <= 0) {
		cout << -1;
		return 0;
	}
	cout << x << " " << y;


	return 0;
}