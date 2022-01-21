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
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	int same_cnt = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(i, 0, N - 1) {
		cin >> B[i];
		if (A[i] == B[i]) {
			same_cnt++;
		}
	}
	bool flag = false;
	if (same_cnt == N) {
		flag = true;
	}
	ROF(i, N - 1, 1) {
		FOR(j, 0, i - 1) {
			if (A[j] > A[j + 1]) {
				same_cnt += (-1) * (A[j] == B[j]);
				same_cnt += (-1) * (A[j + 1] == B[j + 1]);
				swap(A[j], A[j + 1]);
				same_cnt += (A[j] == B[j]);
				same_cnt += (A[j + 1] == B[j + 1]);
				if (same_cnt == N) {
					flag = true;
				}
			}
		}
	}

	cout << flag;

	return 0;
}