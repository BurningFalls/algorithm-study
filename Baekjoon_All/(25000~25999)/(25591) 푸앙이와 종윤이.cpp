#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int x, y;
	cin >> x >> y;
	int a = 100 - x;
	int b = 100 - y;
	int c = 100 - (a + b);
	int d = a * b;
	int q = d / 100;
	int r = d % 100;
	cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << "\n";
	cout << c + q << " " << r;

	return 0;
}