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
	int X;
	cin >> X;
	if (X == 0) {
		cout << "GBSISTHEBEST";
		return 0;
	}
	vector<int> v;
	while (X != 0) {
		int sqrtx = sqrt(X);
		v.push_back(sqrtx);
		X -= sqrtx * sqrtx;
	}
	FOR(i, 0, LEN(v) - 1) {
		FOR(j, 1, v[i]) {
			cout << 'A';
		}
		FOR(j, 1, 24) {
			char tmp = 'A' + j;
			cout << tmp;
		}
		FOR(j, 1, v[i]) {
			cout << 'Z';
		}
	}

	return 0;
}