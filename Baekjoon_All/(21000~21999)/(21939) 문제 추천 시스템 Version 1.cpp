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
	PQ<pii> big_pq, small_pq;
	vector<int> check(100001, 0);
	FOR(i, 1, N) {
		int P, L;
		cin >> P >> L;
		big_pq.push({ L, P });
		small_pq.push({ -L, -P });
		check[P] = L;
	}
	int M;
	cin >> M;
	FOR(m, 1, M) {
		string s;
		int x, P, L;
		cin >> s;
		if (s == "recommend") {
			cin >> x;
			if (x == 1) {
				while (!big_pq.empty() && check[big_pq.top().second] != big_pq.top().first) {
					big_pq.pop();
				}
				cout << big_pq.top().second;
			}
			else if (x == -1) {
				while (!small_pq.empty() && check[-small_pq.top().second] != -small_pq.top().first) {
					small_pq.pop();
				}
				cout << -small_pq.top().second;
			}
			cout << "\n";
		}
		else if (s == "add") {
			cin >> P >> L;
			big_pq.push({ L, P });
			small_pq.push({ -L, -P });
			check[P] = L;
		}
		else if (s == "solved") {
			cin >> P;
			check[P] = 0;
		}
	}

	return 0;
}