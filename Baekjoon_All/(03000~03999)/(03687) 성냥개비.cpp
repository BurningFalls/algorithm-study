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
	vector<int> tmp = { 0, 0, 1, 7, 4, 2, 6, 8 };
	vector<int> tmp2 = { 10, 18, 200, 20, 28, 68, 88 };
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N <= 7) {
			cout << tmp[N];
		}
		else {
			if (N == 10) {
				cout << 22;
			}
			else if (N == 17) {
				cout << 200;
			}
			else {
				int a = (N - 1) % 7;
				cout << tmp2[a];
				int b = (N - 1) / 7;
				if (a == 2) {
					b--;
				}
				FOR(i, 1, b - 1) {
					cout << '8';
				}
			}
		}
		cout << " ";
		if (N % 2 == 0) {
			cout << '1';
		}
		else if (N % 2 == 1) {
			cout << '7';
		}
		FOR(i, 1, N / 2 - 1) {
			cout << '1';
		}
		cout << "\n";
	}


	return 0;
}