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

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, L, R, K;
		cin >> N >> L >> R >> K;
		vector<ll> v(N);
		FOR(i, 0, N - 1) {
			cin >> v[i];
		}
		sort(ALL(v));
		int left = 0, right = N - 1;
		while (left <= N - 1 && v[left] < L) {
			left++;
		}
		while (right >= 0 && v[right] > R) {
			right--;
		}
		ll sum = 0;
		int cnt = 0;
		FOR(i, left, right) {
			if (sum + v[i] > K) {
				break;
			}
			sum += v[i];
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}