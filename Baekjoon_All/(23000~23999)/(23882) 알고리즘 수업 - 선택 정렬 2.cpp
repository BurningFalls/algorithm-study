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

int Find_Max(vector<int>& v, int left, int right) {
	int maxi = 0;
	int idx = 0;
	FOR(i, left, right) {
		if (maxi < v[i]) {
			maxi = v[i];
			idx = i;
		}
	}
	return idx;
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int cnt = 0;
	bool flag = false;
	ROF(i, N - 1, 1) {
		int max_idx = Find_Max(A, 0, i);
		if (max_idx != i) {
			swap(A[max_idx], A[i]);
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
			cout << A[i] << " ";
		}
	}

	return 0;
}