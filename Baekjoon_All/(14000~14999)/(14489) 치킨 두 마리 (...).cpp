#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b >= 2 * c)
		cout << a + b - 2 * c;
	else
		cout << a + b;

	return 0;
}