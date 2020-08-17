#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int a, b, c;
	char x, y;
	cin >> a >> x >> b >> y >> c;
	if (a + b == c)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}