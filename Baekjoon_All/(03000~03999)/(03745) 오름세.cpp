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

vector<int> v(100001);
vector<int> tmp;

int main() {
	FASTIO;
	int N;
	while (cin >> N) {
		v = vector<int>(100001);
		tmp = vector<int>();
		FOR(i, 0, N - 1) {
			cin >> v[i];
		}
		FOR(i, 0, N - 1) {
			if (tmp.empty() || tmp.back() < v[i]) {
				tmp.push_back(v[i]);
				continue;
			}
			int lb = lower_bound(ALL(tmp), v[i]) - tmp.begin();
			tmp[lb] = v[i];
		}
		P1(LEN(tmp));
	}

	return 0;
}