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
#define MAX 300001

int N, M;
vector<ll> A(MAX);
map<ll, int> diff_cnt, div_cnt;

void calcDiff(int idx, int add) {
	if (A[idx] - A[idx - 1] > 0) {
		diff_cnt[A[idx] - A[idx - 1]] += add;
		if (diff_cnt[A[idx] - A[idx - 1]] == 0) {
			diff_cnt.erase(A[idx] - A[idx - 1]);
		}
	}
	else {
		diff_cnt[0] += add;
		if (diff_cnt[0] == 0) {
			diff_cnt.erase(0);
		}
	}
}

void calcDiv(int idx, int add) {
	if (A[idx] % A[idx - 1] == 0) {
		div_cnt[A[idx] / A[idx - 1]] += add;
		if (div_cnt[A[idx] / A[idx - 1]] == 0) {
			div_cnt.erase(A[idx] / A[idx - 1]);
		}
	}
	else {
		div_cnt[0] += add;
		if (div_cnt[0] == 0) {
			div_cnt.erase(0);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	FOR(i, 2, N) {
		calcDiff(i, 1);
		calcDiv(i, 1);
	}

	FOR(m, 1, M) {
		int idx; ll x;
		cin >> idx >> x;
		if (idx == 1) {
			calcDiff(2, -1);
			calcDiv(2, -1);
		}
		else if (idx == N) {
			calcDiff(N, -1);
			calcDiv(N, -1);
		}
		else {
			calcDiff(idx + 1, -1);
			calcDiv(idx + 1, -1);
			calcDiff(idx, -1);
			calcDiv(idx, -1);
		}
		A[idx] = x;
		if (idx == 1) {
			calcDiff(2, 1);
			calcDiv(2, 1);
		}
		else if (idx == N) {
			calcDiff(N, 1);
			calcDiv(N, 1);
		}
		else {
			calcDiff(idx + 1, 1);
			calcDiv(idx + 1, 1);
			calcDiff(idx, 1);
			calcDiv(idx, 1);
		}

		if ((diff_cnt.count(0) == 0 || diff_cnt[0] == 0) && LEN(diff_cnt) == 1) {
			cout << '+';
		}
		else if ((div_cnt.count(0) == 0 || div_cnt[0] == 0) && LEN(div_cnt) == 1) {
			cout << '*';
		}
		else {
			cout << '?';
		}
		cout << "\n";
	}

	return 0;
}