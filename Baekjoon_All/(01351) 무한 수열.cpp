#include <iostream>
#include <map>
using namespace std;

typedef long long ll_t;

map<ll_t, ll_t> dp;
long long recursive(ll_t N, ll_t P, ll_t Q) {
	if (N == 0)
		return 1;
	else if (dp[N])
		return dp[N];

	return dp[N] = recursive(N / P, P, Q) + recursive(N / Q, P, Q);
}

int main() {
	ll_t N, P, Q;
	cin >> N >> P >> Q;
	cout << recursive(N, P, Q);

	return 0;
}