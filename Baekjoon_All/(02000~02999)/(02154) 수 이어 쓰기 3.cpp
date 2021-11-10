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
	int N;
	string s = "";
	cin >> N;
	string sn = to_string(N);
	FOR(i, 1, N) {
		s += to_string(i);
	}
	int len = LEN(sn);
	int left = 0, right = len - 1;
	while (right <= LEN(s) - 1) {
		bool flag = true;
		FOR(i, 0, len - 1) {
			if (s[left + i] != sn[i]) {
				flag = false;
			}
		}
		if (flag) break;
		left++;
		right++;
	}
	cout << left + 1;

	return 0;
}