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
	int N, K, M;
	cin >> N >> K >> M;

	FOR(t, 1, M) {
		FOR(i, 1, K) {
			cout << i << " ";
		}
		cout << endl;
		FOR(i, 1, N - K) {
			int x;
			cin >> x;
		}
	}

	return 0;
}