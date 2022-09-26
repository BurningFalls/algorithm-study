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
	vector<string> s(N);
	FOR(i, 0, N - 1) {
		cin >> s[i];
	}
	bool ans = true;
	FOR(i, 0, N - 2) {
		bool flag = false;
		FOR(j, 1, M) {
			string a = s[i].substr(0, j);
			string b = s[i + 1].substr(M - j, j);
			if (a == b) {
				flag = true;
				break;
			}
		}
		FOR(j, 1, M) {
			string a = s[i].substr(M - j, j);
			string b = s[i + 1].substr(0, j);
			if (a == b) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			ans = false;
			break;
		}
	}
	cout << ans;

	return 0;
}