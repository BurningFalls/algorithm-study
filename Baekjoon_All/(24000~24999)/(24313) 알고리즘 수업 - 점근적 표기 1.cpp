#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	if (a1 * n0 + a0 > c * n0) {
		cout << 0;
	}
	else if (a1 * n0 + a0 <= c * n0) {
		cout << (a1 <= c);
	}

	return 0;
}