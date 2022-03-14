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
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int odd = 0, even = 0;
		FOR(i, 0, 2) {
			int num;
			cin >> num;
			if (num % 2 == 0) {
				even++;
			}
			else if (num % 2 == 1) {
				odd++;
			}
		}
		if (even >= 2) {
			cout << 'R';
		}
		else if (odd >= 2) {
			cout << 'B';
		}
		cout << "\n";
	}

	return 0;
}