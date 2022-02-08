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

int Calc(int x) {
	int y = (x >> 2) << 2;
	int ans = 0;
	FOR(i, y, x) {
		ans ^= i;
	}
	return ans;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int S, T;
		cin >> S >> T;
		cout << (Calc(S - 1) ^ Calc(T)) << "\n";
	}

	return 0;
}