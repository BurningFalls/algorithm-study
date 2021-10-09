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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

vector<char> v(300001);

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		char C;
		cin >> N >> C;
		bool flag = false;
		int cnt = 0;
		FOR(i, 1, N) {
			cin >> v[i];
			if (v[i] != C)
				cnt++;
			if (i == N && v[i] != C) {
				flag = true;
			}
		}
		if (cnt == 0) {
			P1(0);
		}
		else if (!flag) {
			P1(1);
			P1(N);
		}
		else {
			bool f = true;
			int idx = N;
			while (idx >= 1 && v[idx] != C)
				idx--;
			if (idx != 0) {
				FOR(i, idx + 1, N) {
					if (i % idx == 0)
						f = false;
				}
			}
			if (idx != 0 && f) {
				P1(1);
				P1(idx);
			}
			else {
				P1(2);
				P2(N, N - 1);
			}
		}
	}
}
