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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<ll> v(N);
		vector<ll> sum(N);
		FOR(i, 0, N - 1) {
			cin >> v[i];
			if (i == 0) {
				sum[i] = v[i];
			}
			else {
				sum[i] = sum[i - 1] + v[i];
			}
		}
		bool flag = true;
		FOR(i, 0, N - 1) {
			if (sum[i] < 0) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << "No\n";
			continue;
		}

		flag = true;
		bool flag2 = false;
		FOR(i, 0, N - 1) {
			if (sum[i] == 0) {
				flag2 = true;
			}
			else {
				if (flag2) {
					flag = false;
					break;
				}
			}
		}
		if (!flag2) {
			flag = false;
		}
		cout << (flag ? "Yes" : "No") << "\n";
	}

	return 0;
}