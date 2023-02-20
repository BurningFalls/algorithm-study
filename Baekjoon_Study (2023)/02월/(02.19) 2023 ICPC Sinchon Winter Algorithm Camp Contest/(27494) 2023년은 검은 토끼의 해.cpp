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
	int N;
	cin >> N;
	int cnt = 0;
	vector<int> v = { 2, 0, 2, 3 };
	FOR(num, 2023, N) {
		string s = to_string(num);
		int idx = 0;
		FOR(i, 0, LEN(s) - 1) {
			if (idx == 4) break;
			if (s[i] - '0' == v[idx]) {
				idx++;
			}
		}
		cnt += (idx == 4);
	}
	cout << cnt;

	return 0;
}