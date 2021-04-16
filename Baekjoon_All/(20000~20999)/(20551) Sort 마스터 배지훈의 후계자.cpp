#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A[200001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 0, N - 1)
		cin >> A[i];
	sort(A, A + N);
	FOR(i, 1, M) {
		int D;
		cin >> D;
		if (D > A[N - 1])
			cout << -1;
		else {
			int lb = lower_bound(A, A + N, D) - A;
			if (D == A[lb])
				cout << lb;
			else
				cout << -1;
		}
		cout << "\n";
	}


	return 0;
}