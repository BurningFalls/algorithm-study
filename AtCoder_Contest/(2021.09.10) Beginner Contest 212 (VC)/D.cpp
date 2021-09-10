#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int Q;
	cin >> Q;
	ll adding = 0;
	priority_queue<ll> pq;
	FOR(q, 1, Q) {
		int P;
		ll X;
		cin >> P;
		if (P == 1) {
			cin >> X;
			pq.push(-(X - adding));
		}
		else if (P == 2) {
			cin >> X;
			adding += X;
		}
		else if (P == 3) {
			cout << -pq.top() + adding << "\n";
			pq.pop();
		}
	}

	return 0;
}