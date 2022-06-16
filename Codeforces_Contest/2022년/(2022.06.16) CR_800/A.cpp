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
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		if (a <= b) {
			FOR(i, 1, a) {
				cout << "10";
			}
			FOR(i, 1, b - a) {
				cout << "1";
			}
		}
		else if (a > b) {
			FOR(i, 1, b) {
				cout << "01";
			}
			FOR(i, 1, a - b) {
				cout << "0";
			}
		}
		cout << "\n";
	}


	return 0;
}