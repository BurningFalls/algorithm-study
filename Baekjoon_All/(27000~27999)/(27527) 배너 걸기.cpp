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
	int N; double M;
	cin >> N >> M;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int len = ceil(9 * M / 10);
	vector<int> cnt(1000001, 0);
	bool flag = false;
	FOR(i, 0, M - 1) {
		cnt[A[i]]++;
	}
	FOR(i, 1, 1000000) {
		flag |= (cnt[i] >= len);
	}

	FOR(i, M, N - 1) {
		cnt[A[i]]++;
		cnt[A[i - M]]--;
		flag |= (cnt[A[i]] >= len || cnt[A[i - M]] >= len);
	}

	cout << (flag ? "YES" : "NO");

	return 0;
}