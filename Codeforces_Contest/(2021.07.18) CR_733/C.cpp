#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A[200002];
int sum_A[200002];
int B[200002];
int sum_B[200002];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(sum_A, 0, sizeof(sum_A));
		memset(sum_B, 0, sizeof(sum_B));
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> A[i];
		FOR(i, 1, N)
			cin >> B[i];
		sort(A + 1, A + N + 1);
		sort(B + 1, B + N + 1);
		FOR(i, 1, N)
			sum_A[i] = sum_A[i - 1] + A[i];
		FOR(i, 1, N)
			sum_B[i] = sum_B[i - 1] + B[i];
		int size = N;
		int K = size - size / 4;
		int idx = 0;
		int resultA = sum_A[size] - sum_A[size - K];
		int resultB = sum_B[size] - sum_B[size - K];
		while (resultA < resultB) {
			size++;
			A[size] = 100;
			sum_A[size] = sum_A[size - 1] + 100;
			K = size - size / 4;
			resultA = sum_A[size] - sum_A[size - K];
			if (K > N) {
				resultB = sum_B[N];
			}
			else if (K <= N) {
				resultB = sum_B[N] - sum_B[N - K];
			}
			idx++;
		}
		cout << idx << "\n";
	}


	return 0;
}