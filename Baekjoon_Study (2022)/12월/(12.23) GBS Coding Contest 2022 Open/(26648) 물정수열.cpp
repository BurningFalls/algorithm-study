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
	vector<int> A(N), B(N), C(N);
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(i, 0, N - 1) {
		cin >> B[i];
	}
	FOR(i, 0, N - 1) {
		cin >> C[i];
	}

	bool flag = true;
	v[0] = min({ A[0], B[0], C[0] });
	FOR(i, 1, N - 1) {
		vector<int> tmp = { A[i], B[i], C[i] };
		sort(ALL(tmp));
		if (v[i - 1] + 1 > tmp[2]) {
			flag = false;
			break;
		}
		else {
			v[i] = max(v[i - 1] + 1, tmp[0]);
		}
	}
	cout << (flag ? "YES" : "NO");

	return 0;
}