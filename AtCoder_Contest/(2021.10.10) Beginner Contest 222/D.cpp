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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define MOD 998244353

vector<int> A(3001);
vector<int> B(3001);
vector<int> C(3001, 0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(i, 0, N - 1) {
		cin >> B[i];
	}
	FOR(i, A[0], B[0]) {
		C[i] = 1;
	}
	FOR(i, 1, N - 1) {
		int sum = 0;
		FOR(j, A[i - 1], A[i]) {
			sum = (sum + C[j]) % MOD;
		}
		C[A[i]] = sum;
		FOR(j, A[i] + 1, B[i]) {
			C[j] = (C[j] + C[j - 1]) % MOD;
		}
	}
	int ans = 0;
	FOR(i, A[N - 1], B[N - 1]) {
		ans = (ans + C[i]) % MOD;
	}
	P1(ans);

	return 0;
}