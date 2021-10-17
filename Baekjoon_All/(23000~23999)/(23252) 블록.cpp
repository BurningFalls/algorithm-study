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
		ll A, B, C;
		cin >> A >> B >> C;
		if (B % 2 == 0) {
			if (A > C) {
				cout << ((A - C) % 2 == 0 ? "Yes" : "No");
			}
			else if (A == C) {
				cout << "Yes";
			}
			else if (A < C) {
				cout << "No";
			}
		}
		else if (B % 2 == 1) {
			if (A == 0 && C == 0) {
				cout << "No";
			}
			else if (A == 0) {
				cout << "No";
			}
			else if (C == 0) {
				cout << (A % 2 == 0 ? "Yes" : "No");
			}
			else {
				if (A > C) {
					cout << ((A - C) % 2 == 0 ? "Yes" : "No");
				}
				else if (A == C) {
					cout << "Yes";
				}
				else if (A < C) {
					cout << "No";
				}
			}
		}
		cout << "\n";
	}


	return 0;
}