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
	PQ<int> pq;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		pq.push(num);
	}
	int ans = 0;
	while (LEN(pq) >= 2) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		if (--a != 0) pq.push(a);
		if (--b != 0) pq.push(b);
		ans++;
		if (ans > 1440) break;
	}
	if (!pq.empty()) {
		ans += pq.top();
	}
	cout << (ans > 1440 ? -1 : ans);

	return 0;
}