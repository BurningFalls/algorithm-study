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
		}
		int cnt = 0;
		bool flag = false;
		FOR(i, 0, N - 1) {
			if (A[i] == 0) {
				if (!flag) {
					flag = true;
					cnt++;
				}
			}
			else if (A[i] != 0) {
				flag = false;
			}
		}
		if (A[0] == 0) {
			cnt--;
		}
		if (A[N - 1] != 0) {
			cnt++;
		}
		cout << min(2, cnt) << "\n";
	}

	return 0;
}