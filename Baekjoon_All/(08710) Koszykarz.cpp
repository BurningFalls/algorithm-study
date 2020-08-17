#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((b - a) % c == 0)
		cout << (b - a) / c;
	else
		cout << (b - a) / c + 1;

	return 0;
}