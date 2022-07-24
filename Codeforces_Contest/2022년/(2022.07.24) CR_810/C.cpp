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

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll N, M, K;
		cin >> N >> M >> K;
		vector<ll> A(K);
		FOR(i, 0, K - 1) {
			cin >> A[i];
		}

		bool f1 = false, f2 = false;
		
		ll sum = 0;
		ll cnt = 0;
		ll two = 0;
		FOR(i, 0, K - 1) {
			ll tmp = A[i] / N;
			if (tmp == 2) {
				two++;
			}
			if (tmp >= 2) {
				sum += tmp;
				cnt++;
			}
		}
		if (two == cnt) {
			f1 = (sum >= M && (sum - M) % 2 == 0);
		}
		else if (two != cnt) {
			f1 = (sum >= M);
		}

		sum = 0;
		cnt = 0;
		two = 0;
		FOR(i, 0, K - 1) {
			ll tmp = A[i] / M;
			if (tmp == 2) {
				two++;
			}
			if (tmp >= 2) {
				sum += tmp;
				cnt++;
			}
		}
		if (two == cnt) {
			f2 = (sum >= N && (sum - N) % 2 == 0);
		}
		else if (two != cnt) {
			f2 = (sum >= N);
		}

		cout << (f1 || f2 ? "Yes" : "No") << "\n";
	}

	return 0;
}