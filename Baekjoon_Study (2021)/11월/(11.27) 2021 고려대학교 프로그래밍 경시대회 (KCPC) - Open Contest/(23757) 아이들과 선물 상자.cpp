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
	cin >> N >> M;
	PQ<int> pq;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		pq.push(num);
	}
	bool flag = true;
	FOR(i, 0, M - 1) {
		int num;
		cin >> num;
		if (pq.empty()) {
			flag = false;
			break;
		}
		int t = pq.top();
		pq.pop();
		if (t < num) {
			flag = false;
			break;
		}
		if (t - num != 0) {
			pq.push(t - num);
		}
	}
	cout << flag;


	return 0;
}