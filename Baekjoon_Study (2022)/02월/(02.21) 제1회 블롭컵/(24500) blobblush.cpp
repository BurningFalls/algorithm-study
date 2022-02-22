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
	ll N;
	cin >> N;
	int cnt = 0;
	ll n = N;
	while (n) {
		n /= 2;
		cnt++;
	}
	ll num = 1;
	FOR(i, 1, cnt) {
		num *= 2;
	}
	num -= 1;
	if (N == num) {
		cout << 1 << "\n" << N;
	}
	else {
		cout << 2 << "\n" << num - N << " " << N;
	}


	return 0;
}