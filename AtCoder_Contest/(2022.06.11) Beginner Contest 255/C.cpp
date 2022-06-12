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
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	ll X, A, D, N;
	cin >> X >> A >> D >> N;
	ll start = A;
	ll end = A + (N - 1) * D;
	if (D == 0) {
		cout << llabs(A - X);
	}
	else if ((D > 0 && X < start) || (D < 0 && X > start)) {
		cout << llabs(start - X);
	}
	else if ((D > 0 && end < X) || (D < 0 && end > X)) {
		cout << llabs(X - end);
	}
	else {
		ll tmp = llabs(X - A) % llabs(D);
		cout << min(tmp, llabs(D) - tmp);
	}


	return 0;
}