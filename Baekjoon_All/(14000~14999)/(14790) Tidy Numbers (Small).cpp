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
	FOR(t, 1, T) {
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		while (true) {
			string s = to_string(N);
			bool flag = true;
			FOR(i, 0, LEN(s) - 2) {
				if (s[i] > s[i + 1]) {
					flag = false;
					break;
				}
			}
			if (flag) break;
			N--;
		}
		cout << N << "\n";
	}

	return 0;
}