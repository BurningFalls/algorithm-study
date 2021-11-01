#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N;
int Cnt[37250];
int Country[37250];

int main() {
	FASTIO;
	cin >> N;
	int sum = 0;
	FOR(n, 1, N) {
		int V, E;
		cin >> V >> E;
		Cnt[n] = V;
		Country[n] = sum + 1;
		sum += V;
		FOR(e, 1, E) {
			int a, b;
			cin >> a >> b;
			Cnt[n]--;
		}
	}
	int Q;
	cin >> Q;
	FOR(q, 1, Q) {
		int order, k, u, v;
		cin >> order;
		if (order == 1) {
			cin >> k;
			cout << Cnt[k] << "\n";
		}
		else if (order == 2) {
			cin >> u >> v;
			int ub = upper_bound(Country + 1, Country + N + 1, u) - Country;
			ub--;
			Cnt[ub]++;
		}
		else if (order == 3) {
			cin >> u >> v;
			int ub = upper_bound(Country + 1, Country + N + 1, u) - Country;
			ub--;
			Cnt[ub]--;
		}
	}


	return 0;
}