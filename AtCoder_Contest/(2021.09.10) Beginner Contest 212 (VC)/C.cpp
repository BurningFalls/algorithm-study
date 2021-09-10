#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int A[200001];
int B[200001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> A[i];
	FOR(i, 1, M)
		cin >> B[i];
	int mini = 2100000000;
	sort(A + 1, A + N + 1);
	sort(B + 1, B + M + 1);
	int a_idx = 1;
	int b_idx = 1;
	while (a_idx <= N && b_idx <= M) {
		mini = min(mini, abs(A[a_idx] - B[b_idx]));
		if (A[a_idx] > B[b_idx])
			b_idx++;
		else if (A[a_idx] < B[b_idx])
			a_idx++;
		else if (A[a_idx] == B[b_idx])
			break;
	}
	cout << mini;

	return 0;
}