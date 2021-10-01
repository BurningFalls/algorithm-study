#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int Calc(int a, int b, char x) {
	if (x == '+')
		return a + b;
	else if (x == '-')
		return a - b;
	else if (x == '*')
		return a * b;
	else if (x == '/')
		return a / b;
}

int main() {
	FASTIO;
	int a, b, c;
	char x, y;
	cin >> a >> x >> b >> y >> c;
	int r1 = Calc(Calc(a, b, x), c, y);
	int r2 = Calc(a, Calc(b, c, y), x);
	cout << min(r1, r2) << "\n" << max(r1, r2);


	return 0;
}