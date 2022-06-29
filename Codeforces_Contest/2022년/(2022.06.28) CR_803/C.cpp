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
		vector<ll> A(N);
		vector<ll> v;
		int zero_cnt = 0;
		FOR(i, 0, N - 1) {
			cin >> A[i];
			if (A[i] != 0) {
				v.push_back(A[i]);
			}
			else if (A[i] == 0) {
				zero_cnt++;
			}
		}
		int len = LEN(v);
		bool flag = true;
		if (len <= 1) {
			flag = true;
		}
		else if (len == 2) {
			flag = (v[0] + v[1] == 0);
		}
		else if (3 <= len && len <= 4) {
			if (zero_cnt != 0) {
				v.push_back(0);
			}
			len = LEN(v);
			FOR(i, 0, len - 1) {
				FOR(j, i + 1, len - 1) {
					FOR(k, j + 1, len - 1) {
						ll sum = v[i] + v[j] + v[k];
						bool f = false;
						FOR(n, 0, len - 1) {
							if (sum == v[n]) {
								f = true;
							}
						}
						if (!f) {
							flag = false;
						}
					}
				}
			}
		}
		else if (len > 4) {
			flag = false;
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}