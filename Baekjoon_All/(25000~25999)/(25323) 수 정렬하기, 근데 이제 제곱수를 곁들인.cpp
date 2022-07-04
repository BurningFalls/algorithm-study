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

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> A(N), B(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
		B[i] = A[i];
	}
	sort(ALL(B));

	bool flag = true;
	FOR(i, 0, N - 1) {
		ll gcd = Gcd(A[i], B[i]);
		A[i] /= gcd;
		B[i] /= gcd;
		ll sqrta = sqrt(A[i]);
		ll sqrtb = sqrt(B[i]);
		if (sqrta * sqrta != A[i] || sqrtb * sqrtb != B[i]) {
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO");

	return 0;
}