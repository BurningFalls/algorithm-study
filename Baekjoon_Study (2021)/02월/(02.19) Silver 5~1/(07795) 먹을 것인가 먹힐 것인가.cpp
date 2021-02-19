#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int A[20001];
int B[20001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		int ans = 0;
		cin >> N >> M;
		FOR(i, 1, N)
			cin >> A[i];
		FOR(i, 1, M)
			cin >> B[i];
		sort(A + 1, A + N + 1);
		sort(B + 1, B + M + 1);
		FOR(i, 1, M) {
			int ub = upper_bound(A + 1, A + N + 1, B[i]) - A;
			ans += N - ub + 1;
			if (ub > N)
				break;
		}
		cout << ans << "\n";
	}


	return 0;
}