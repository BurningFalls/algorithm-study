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
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(i, 0, M - 1) {
		cin >> B[i];
	}
	int Aidx = 0, Bidx = 0;
	int ans = 0;
	while (Aidx < N && Bidx < M) {
		int sum = 0;
		while (Bidx < M && sum + B[Bidx] <= A[Aidx]) {
			sum += B[Bidx];
			Bidx++;
		}
		ans += A[Aidx] - sum;
		Aidx++;
	}
	FOR(i, Aidx, N - 1) {
		ans += A[i];
	}
	cout << ans;

	return 0;
}