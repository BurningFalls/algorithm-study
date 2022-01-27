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
	ll n, n1;
	cin >> n;
	n1 = n;
	int cnt = 0;
	while (n) {
		n /= 2;
		cnt++;
	}
	ll n2 = (1LL << 32) - n1;
	int ans = 0;
	FOR(i, 0, 31) {
		bool f1 = (n1 & (1LL << i));
		bool f2 = (n2 & (1LL << i));
		ans += f1 ^ f2;
	}
	cout << ans;

	return 0;
}