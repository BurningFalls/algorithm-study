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
		int N;
		cin >> N;
		vector<int> A(N);
		FOR(i, 0, N - 1) {
			cin >> A[i];
			if (A[i] % 10 == 5) {
				A[i] += 5;
			}
			else if (A[i] % 10 == 1) {
				A[i] += 1;
			}
			else if (A[i] % 10 == 3) {
				A[i] += 9;
			}
			else if (A[i] % 10 == 6) {
				A[i] += 6;
			}
			else if (A[i] % 10 == 7) {
				A[i] += 7;
			}
			else if (A[i] % 10 == 9) {
				A[i] += 9;
			}
		}
		int zero_cnt = 0;
		FOR(i, 0, N - 1) {
			if (A[i] % 10 == 0) {
				zero_cnt++;
			}
		}
		if (zero_cnt == N) {
			bool flag = true;
			FOR(i, 1, N - 1) {
				if (A[0] != A[i]) {
					flag = false;
					break;
				}
			}
			cout << (flag ? "Yes" : "No") << "\n";
		}
		else if (zero_cnt == 0) {
			int odd = 0, even = 0;
			FOR(i, 0, N - 1) {
				odd += ((A[i] / 10) % 2 == 1);
				even += ((A[i] / 10) % 2 == 0);
			}
			cout << (odd == N || even == N ? "Yes" : "No") << "\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}