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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N % 2 == 0) {
			for (int i = 1; i <= N - 1; i += 2) {
				cout << i + 1 << " " << i << " ";
			}
		}
		else if (N % 2 == 1) {
			cout << 1 << " ";
			for (int i = 2; i <= N - 1; i += 2) {
				cout << i + 1 << " " << i << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}