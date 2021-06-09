#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a < b && b < c && c < d)
		cout << "Fish Rising";
	else if (a > b&& b > c&& c > d)
		cout << "Fish Diving";
	else if (a == b && b == c && c == d)
		cout << "Fish At Constant Depth";
	else
		cout << "No Fish";


	return 0;
}