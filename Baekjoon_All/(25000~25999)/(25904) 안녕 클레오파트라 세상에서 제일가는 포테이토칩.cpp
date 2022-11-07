#include <bits/stdc++.h>
using namespace std;

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
	int N, X;
	cin >> N >> X;
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	int num = X;
	int idx = 0;
	while (num <= v[idx]) {
		num++;
		idx = (idx + 1) % N;
	}
	cout << idx + 1;

	return 0;
}