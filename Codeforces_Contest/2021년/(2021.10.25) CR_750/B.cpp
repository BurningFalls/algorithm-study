#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int zero_cnt = 0;
		ll one_cnt = 0;
		FOR(i, 0, N - 1) {
			int num;
			cin >> num;
			if (num == 0) {
				zero_cnt++;
			}
			else if (num == 1) {
				one_cnt++;
			}
		}
		ll tmp = 1;
		FOR(i, 1, zero_cnt) {
			tmp *= 2;
		}
		cout << one_cnt * tmp << "\n";
	}


	return 0;
}