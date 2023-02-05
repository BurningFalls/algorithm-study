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
	int M, N, Q;
	cin >> M >> N >> Q;
	vector<int> A(N);
	vector<int> check(N, 0);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	FOR(q, 1, min(M, Q)) {
		cout << "? " << q << " " << q << endl;
		int x;
		cin >> x;
		check[q - 1] = x;
	}
	cout << "! ";
	FOR(i, 0, N - 1) {
		cout << (check[i] == 1 ? 2 : 1) << " ";
	}
	cout << endl;

	return 0;
}