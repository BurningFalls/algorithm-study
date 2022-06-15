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
		vector<int> A(N);
		vector<int> cnt(10001, 0);
		int tmp = 0;
		FOR(i, 0, N - 1) {
			cin >> A[i];
			if (cnt[A[i]] == 0) {
				tmp++;
			}
			cnt[A[i]]++;
		}
		cout << tmp - (N - tmp) % 2 << "\n";
	}

	return 0;
}