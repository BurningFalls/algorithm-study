#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int w[21][21][21];

int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return W(20, 20, 20);
	int& ret = w[a][b][c];
	if (ret != -1)
		return ret;
	if (a < b && b < c)
		return ret = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
	return ret = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}

int main() {
	FASTIO;
	int a, b, c;
	memset(w, -1, sizeof(w));
	while (true) {
		int ans = 0;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		ans = W(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
	}

	return 0;
}