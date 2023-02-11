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
	int N, M;
	cin >> N >> M;
	vector<int> T(N);
	FOR(i, 0, N - 1) {
		cin >> T[i];
	}

	int idx = 0;
	int toggy = 0, coffee = 0;
	bool flag = true;
	FOR(t, 0, 1000000) {
		if (idx >= N || coffee >= N) break;
		if (t == T[idx]) {
			if (toggy <= idx || coffee <= idx) {
				flag = false;
				break;
			}
			idx++;
		}
		else if (T[coffee] <= t) {
			flag = false;
			break;
		}
		else if (T[coffee] - M <= t) {
			if (coffee == toggy) {
				toggy++;
			}
			else if (coffee < toggy) {
				coffee++;
			}
			else if (coffee > toggy) {
				flag = false;
				break;
			}
		}
		else {
			toggy++;
		}
	}

	cout << (flag ? "success" : "fail");

	return 0;
}