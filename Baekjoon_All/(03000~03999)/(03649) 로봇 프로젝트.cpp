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

int main() {
	FASTIO;
	int X;
	while (cin >> X) {
		X *= 10000000;
		int N;
		cin >> N;
		vector<int> v(N);
		FOR(i, 0, N - 1) {
			cin >> v[i];
		}
		sort(ALL(v));
		bool ans = false;
		FOR(i, 0, N - 1) {
			if (v[i] * 2 > X) break;
			bool flag = binary_search(v.begin() + i + 1, v.end(), X - v[i]);
			if (flag) {
				ans = true;
				cout << "yes " << v[i] << " " << X - v[i] << "\n";
				break;
			}
		}
		if (!ans) {
			cout << "danger\n";
		}
	}

	return 0;
}