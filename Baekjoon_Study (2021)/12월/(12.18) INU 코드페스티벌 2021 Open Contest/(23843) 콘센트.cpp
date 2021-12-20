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

int main() {
	FASTIO;
	int N, M;
	PQ<int> pq;
	cin >> N >> M;
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	sort(ALL(v), greater<int>());

	FOR(i, 1, M) {
		pq.push(0);
	}
	int maxi = 0;
	FOR(i, 0, N - 1) {
		int node = -pq.top();
		pq.pop();
		int next = node + v[i];
		maxi = max(maxi, next);
		pq.push(-next);
	}
	cout << maxi;


	return 0;
}