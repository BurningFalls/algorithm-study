#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> A(N + 1);
	vector<int> score(10);
	vector<int> sep = { 0, 4, 11, 23, 40, 60, 77, 89, 96, 100 };
	vector<int> ans(10, 0);
	FOR(i, 1, N) {
		cin >> A[i];
	}
	sort(A.begin() + 1, A.end(), greater<int>());
	FOR(i, 1, 9) {
		score[i] = A[sep[i]];
	}

	int pos = 1;
	FOR(i, 1, 9) {
		int idx = sep[i];
		while (idx <= 100 && A[idx] == score[i]) {
			idx++;
		}
		ans[i] = max(0, idx - pos);
		pos = max(pos, idx);
	}
	FOR(i, 1, 9) {
		cout << ans[i] << "\n";
	}

	return 0;
}