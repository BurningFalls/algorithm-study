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
	int N; double L;
	cin >> N >> L;
	vector<double> X(N), W(N);
	FOR(i, 0, N - 1) {
		cin >> X[i];
	}
	FOR(i, 0, N - 1) {
		cin >> W[i];
	}

	double up = 0, down = 0;
	FOR(i, 0, N - 1) {
		up += X[i] * W[i];
		down += W[i];
	}

	cout << fixed << setprecision(6);
	cout << up / down;

	return 0;
}