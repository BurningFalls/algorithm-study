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
	while (N != 0) {
		string s = to_string(N);
		bool flag = false;
		FOR(i, 0, LEN(s) - 1) {
			if (s[i] == '1') {
				flag = true;
				break;
			}
		}
		if (flag) {
			string ns = "";
			FOR(i, 0, LEN(s) - 1) {
				if (s[i] == '1') {
					cnt++;
				}
				else {
					ns += s[i];
				}
			}
			if (ns.empty()) {
				N = 0;
			}
			else {
				N = stoi(ns);
			}
		}
		else if (!flag) {
			int tmp = s[LEN(s) - 1] - '0';
			if (tmp >= 1) {
				cnt += tmp - 1;
				N -= tmp - 1;
			}
			else if (tmp == 0) {
				cnt += 9;
				N -= 9;
			}
		}
	}
	cout << cnt;

	return 0;
}