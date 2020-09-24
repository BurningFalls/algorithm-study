#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int ccw(pii x, pii y, pii z) {
	int t1 = x.first * y.second + y.first * z.second + z.first * x.second;
	int t2 = x.second * y.first + y.second * z.first + z.second * x.first;
	if (t1 > t2)
		return 1;
	else if (t1 == t2)
		return 0;
	else if (t1 < t2)
		return -1;
}

int main() {
	FASTIO;
	pii a, b, c;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	cout << ccw(a, b, c);

	return 0;
}