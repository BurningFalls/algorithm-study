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
	int N, M;
	cin >> N >> M;
	int r = 0, c = 0;
	vector<int> v1(N), v2(M);
	int min1 = INF, min2 = INF;
	FOR(i, 0, N - 1) {
		cin >> v1[i];
		min1 = min(min1, v1[i]);
	}
	v2[0] = v1[N - 1];
	min2 = v2[0];
	FOR(i, 1, M - 1) {
		cin >> v2[i];
		min2 = min(min2, v2[i]);
	}

	FOR(i, 0, N - 1) {
		if (min1 == v1[i]) {
			r = i + 1;
		}
	}
	FOR(i, 0, M - 1) {
		if (min2 == v2[i]) {
			c = i + 1;
		}
	}

	cout << r << " " << c;


	return 0;
}