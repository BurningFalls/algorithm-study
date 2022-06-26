#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int Gcd(int a, int b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M, K;
		cin >> N >> M;
		vector<int> A(N);
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}
		cin >> K;
		vector<int> B(K);
		FOR(i, 0, K - 1) {
			cin >> B[i];
		}
		vector<pll> va, vb;
		FOR(i, 0, N - 1) {
			ll cnt = 1;
			while (A[i] % M == 0) {
				A[i] /= M;
				cnt *= M;
			}
			if (!va.empty() && va.back().first == A[i]) {
				va.back().second += cnt;
			}
			else {
				va.push_back({ A[i], cnt });
			}
		}
		FOR(i, 0, K - 1) {
			ll cnt = 1;
			while (B[i] % M == 0) {
				B[i] /= M;
				cnt *= M;
			}
			if (!vb.empty() && vb.back().first == B[i]) {
				vb.back().second += cnt;
			}
			else {
				vb.push_back({ B[i], cnt });
			}
		}

		if (LEN(va) != LEN(vb)) {
			cout << "No";
		}
		else {
			bool flag = true;
			FOR(i, 0, LEN(va) - 1) {
				if (va[i].first != vb[i].first || va[i].second != vb[i].second) {
					flag = false;
					break;
				}
			}
			cout << (flag ? "Yes" : "No");
		}
		cout << "\n";
	}

	return 0;
}