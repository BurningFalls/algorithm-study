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
	int a1, a0, c1, c2, n0;
	cin >> a1 >> a0 >> c1 >> c2 >> n0;
	if (c1 * n0 <= a1 * n0 + a0 && a1 * n0 + a0 <= c2 * n0) {
		cout << (c1 <= a1 && a1 <= c2);
	}
	else {
		cout << 0;
	}

	return 0;
}