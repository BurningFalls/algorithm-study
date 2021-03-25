#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, Q;
int A[300001];
int sum[300001];

int main() {
	FASTIO;
	cin >> N >> Q;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	sum[0] = 0;
	FOR(i, 1, N) {
		sum[i] = sum[i - 1] + A[i];
	}
	FOR(i, 1, Q) {
		int L, R;
		cin >> L >> R;
		cout << sum[R] - sum[L - 1] << "\n";
	}

	return 0;
}