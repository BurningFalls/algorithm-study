#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a + d) > (b + c))
		cout << (a + d) - (b + c);
	else
		cout << (b + c) - (a + d);
	
	return 0;
}