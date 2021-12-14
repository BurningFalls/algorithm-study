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
	string s = to_string(N);
	ll sum = 0;
	FOR(i, 0, LEN(s) - 1) {
		sum += (s[i] - '0');
	}
	ll tmp = 1;
	FOR(i, 1, LEN(s) - 1) {
		tmp = tmp * 10 + 1;
	}
	cout << sum * tmp;

	return 0;
}