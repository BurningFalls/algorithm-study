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
	string s;
	cin >> N;
	cin >> s;
	int cnt = 0;
	FOR(i, 0, LEN(s) - 1) {
		cnt += (s[i] == 'G');
	}
	string ans = "";
	FOR(bm, 0, (1 << cnt) - 1) {
		int idx = 0;
		string t = s;
		FOR(i, 0, LEN(t) - 1) {
			if (t[i] == 'G') {
				bool flag = (bm & (1 << idx));
				t[i] = (flag ? '(' : ')');
				idx++;
			}
		}
		int left = 0, right = 0;
		bool flag = true;
		FOR(i, 0, LEN(t) - 1) {
			left += (t[i] == '(');
			right += (t[i] == ')');
			if (left < right) {
				flag = false;
				break;
			}
		}
		flag &= (left == right);
		if (flag) {
			ans = t;
			break;
		}
	}
	cout << ans;

	return 0;
}