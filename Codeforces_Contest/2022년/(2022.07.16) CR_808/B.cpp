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
		int N, L, R;
		cin >> N >> L >> R;
		vector<int> ans;
		bool flag = true;
		FOR(i, 1, N) {
			if (L % i == 0) {
				ans.push_back(L);
			}
			else if (L % i != 0) {
				int tmp = (L / i + 1) * i;
				if (tmp > R) {
					flag = false;
					break;
				}
				else if (tmp <= R) {
					ans.push_back(tmp);
				}
			}
		}
		if (!flag) {
			cout << "NO";
		}
		else if (flag) {
			cout << "YES\n";
			FOR(i, 0, N - 1) {
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}