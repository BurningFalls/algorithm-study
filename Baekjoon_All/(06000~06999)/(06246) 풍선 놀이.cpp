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

bool balloon[10001] = { 0, };

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(q, 1, Q) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i <= N; i += b) {
			balloon[i] = 1;
		}
	}
	int cnt = 0;
	FOR(i, 1, N) {
		if (balloon[i] == 0) {
			cnt++;
		}
	}
	cout << cnt;


	return 0;
}