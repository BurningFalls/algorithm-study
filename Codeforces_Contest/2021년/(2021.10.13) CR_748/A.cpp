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
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int maxi = max({ a, b, c });
		if (a != b && b != c && c != a) {
			if (a == maxi) {
				P3(0, maxi + 1 - b, maxi + 1 - c);
			}
			else if (b == maxi) {
				P3(maxi + 1 - a, 0, maxi + 1 - c);
			}
			else if (c == maxi) {
				P3(maxi + 1 - a, maxi + 1 - b, 0);
			}
		}
		else if (a == b && b == c && c == a) {
			P3(1, 1, 1);
		}
		else {
			if (a == maxi && b == maxi) {
				P3(1, 1, maxi + 1 - c);
			}
			else if (b == maxi && c == maxi) {
				P3(maxi + 1 - a, 1, 1);
			}
			else if (c == maxi && a == maxi) {
				P3(1, maxi + 1 - b, 1);
			}
			else if (a == maxi) {
				P3(0, maxi + 1 - b, maxi + 1 - c);
			}
			else if (b == maxi) {
				P3(maxi + 1 - a, 0, maxi + 1 - c);
			}
			else if (c == maxi) {
				P3(maxi + 1 - a, maxi + 1 - b, 0);
			}
		}
	}


	return 0;
}