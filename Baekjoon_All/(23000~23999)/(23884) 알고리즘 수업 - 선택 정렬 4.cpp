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
	int N, K;
	cin >> N >> K;
	vector<NODE> A(N);
	vector<int> Idx(N);
	FOR(i, 0, N - 1) {
		cin >> A[i].num;
		A[i].idx = i;
	}
	sort(ALL(A), compare1);
	FOR(i, 0, N - 1) {
		A[i].ch = i;
	}
	sort(ALL(A), compare2);
	FOR(i, 0, N - 1) {
		Idx[A[i].ch] = i;
	}
	int cnt = 0;
	bool flag = false;
	ROF(i, N - 1, 1) {
		int max_idx = Idx[i];
		int end_idx = i;
		if (max_idx != end_idx) {
			swap(A[max_idx], A[end_idx]);
			swap(Idx[A[max_idx].ch], Idx[A[end_idx].ch]);
			cnt++;
			if (cnt == K) {
				flag = true;
				break;
			}
		}
	}
	if (!flag) {
		cout << -1;
	}
	else {
		FOR(i, 0, N - 1) {
			cout << A[i].num << " ";
		}
	}

	return 0;
}