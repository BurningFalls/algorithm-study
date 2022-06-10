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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	int tmp[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int T;
	cin >> T;
	while (T--) {
		int y, m;
		cin >> y >> m;
		if (m == 1) {
			cout << y - 1 << " " << 12 << " " << 31;
		}
		else {
			cout << y << " " << m - 1 << " ";
			if (m == 3 && ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)) {
				cout << 29;
			}
			else {
				cout << tmp[m - 1];
			}
		}
		cout << "\n";
	}


	return 0;
}