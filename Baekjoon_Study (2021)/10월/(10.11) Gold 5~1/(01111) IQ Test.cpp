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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	if (N == 1) {
		cout << 'A';
		return 0;
	}
	if (N == 2) {
		if (v[0] == v[1]) {
			cout << v[0];
		}
		else {
			cout << 'A';
		}
		return 0;
	}
	int x = 0, y = 0;
	if (v[1] - v[0] != 0) {
		if ((v[2] - v[1]) % (v[1] - v[0]) != 0) {
			cout << 'B';
			return 0;
		}
		else {
			x = (v[2] - v[1]) / (v[1] - v[0]);
		}
	}
	y = v[1] - x * v[0];
	FOR(i, 1, N - 2) {
		if (v[i] * x + y != v[i + 1]) {
			cout << 'B';
			return 0;
		}
	}
	cout << v[N - 1] * x + y;

	return 0;
}