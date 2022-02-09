#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define ld long double
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	ld a, b, c;
	cin >> a >> b >> c;
	ld ans = 229 * 324 * 2 * a + 297 * 420 * 2 * b + 210 * 297 * c;
	cout << fixed << setprecision(6);
	cout << ans / 1000000;

	return 0;
}