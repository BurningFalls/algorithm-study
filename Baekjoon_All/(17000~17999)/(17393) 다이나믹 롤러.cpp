#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll A[500001];
ll B[500001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> A[i];
	FOR(i, 1, N)
		cin >> B[i];
	FOR(i, 1, N) {
		int ub = upper_bound(B + 1, B + N + 1, A[i]) - B;
		cout << ub - i - 1 << " ";
	}


	return 0;
}