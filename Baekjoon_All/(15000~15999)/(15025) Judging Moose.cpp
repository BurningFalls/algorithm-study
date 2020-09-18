#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b;
	cin >> a >> b;
	if (a == 0 && b == 0)
		cout << "Not a moose";
	else if (a == b)
		cout << "Even " << a + b;
	else
		cout << "Odd " << max(a, b) * 2;

	return 0;
}