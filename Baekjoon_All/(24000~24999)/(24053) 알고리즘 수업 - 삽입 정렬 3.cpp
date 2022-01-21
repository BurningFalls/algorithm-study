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

bool Check(int same_cnt, int N, vector<int>&A, vector<int>&B) {
	if (same_cnt == N) {
		return true;
	}
	FOR(i, 1, N - 1) {
		int loc = i - 1;
		int newItem = A[i];
		while (0 <= loc && newItem < A[loc]) {
			same_cnt += (-1) * (A[loc + 1] == B[loc + 1]);
			A[loc + 1] = A[loc];
			loc--;
			same_cnt += (A[loc + 2] == B[loc + 2]);
			if (same_cnt == N) {
				return true;
			}
		}
		if (loc + 1 != i) {
			same_cnt += (-1) * (A[loc + 1] == B[loc + 1]);
			A[loc + 1] = newItem;
			same_cnt += (A[loc + 1] == B[loc + 1]);
			if (same_cnt == N) {
				return true;
			}
		}
	}
	return false;
}

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

	cout << Check(same_cnt, N, A, B);

	return 0;
}