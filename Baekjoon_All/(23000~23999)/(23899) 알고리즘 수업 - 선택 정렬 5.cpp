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

struct NODE {
	int num;
	int ch;
	int idx;
};

bool compare1(NODE a, NODE b) {
	return a.num < b.num;
}

bool compare2(NODE a, NODE b) {
	return a.idx < b.idx;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<NODE> A(N);
	vector<int> B(N);
	vector<int> Idx(N);
	int same_cnt = 0;
	FOR(i, 0, N - 1) {
		cin >> A[i].num;
		A[i].idx = i;
	}
	FOR(i, 0, N - 1) {
		cin >> B[i];
		if (A[i].num == B[i]) {
			same_cnt++;
		}
	}
	sort(ALL(A), compare1);
	FOR(i, 0, N - 1) {
		A[i].ch = i;
	}
	sort(ALL(A), compare2);
	FOR(i, 0, N - 1) {
		Idx[A[i].ch] = i;
	}
	bool flag = false;
	if (same_cnt == N) {
		flag = true;
	}
	ROF(i, N - 1, 1) {
		int max_idx = Idx[i];
		int end_idx = i;
		if (max_idx != end_idx) {
			same_cnt += (-1) * (A[max_idx].num == B[max_idx]);
			same_cnt += (-1) * (A[end_idx].num == B[end_idx]);
			swap(A[max_idx], A[end_idx]);
			swap(Idx[A[max_idx].ch], Idx[A[end_idx].ch]);
			same_cnt += (A[max_idx].num == B[max_idx]);
			same_cnt += (A[end_idx].num == B[end_idx]);
		}
		if (same_cnt == N) {
			flag = true;
		}
	}

	cout << flag;

	return 0;
}