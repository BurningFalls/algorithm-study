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
		int N;
		cin >> N;
		vector<int> v(N);
		vector<int> blue, red;
		FOR(i, 0, N - 1) {
			cin >> v[i];
		}
		FOR(i, 0, N - 1) {
			char color;
			cin >> color;
			if (color == 'R') {
				red.push_back(v[i]);
			}
			else if (color == 'B') {
				blue.push_back(v[i]);
			}
		}
		sort(ALL(blue));
		sort(ALL(red), greater<int>());
		bool flag = true;
		FOR(i, 0, LEN(blue) - 1) {
			if (i + 1 > blue[i]) {
				flag = false;
			}
		}
		FOR(i, 0, LEN(red) - 1) {
			if (N - i < red[i]) {
				flag = false;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}