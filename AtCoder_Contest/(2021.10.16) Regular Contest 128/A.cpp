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
	int N;
	cin >> N;
	vector<int> v(N);
	vector<bool> ans(N, 0);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	bool flag = false;
	int store = 0;
	FOR(i, 0, N - 2) {
		if (!flag) {
			if (v[i] > v[i + 1]) {
				store = i;
				flag = true;
			}
		}
		else if (flag) {
			if (v[i] < v[i + 1]) {
				ans[store] = 1;
				ans[i] = 1;
				flag = false;
			}
		}
	}
	if (flag) {
		ans[store] = 1;
		ans[N - 1] = 1;
	}
	FOR(i, 0, N - 1) {
		cout << ans[i] << " ";
	}

	return 0;
}