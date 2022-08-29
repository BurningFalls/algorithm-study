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

int N;
string ans = "";

void Func() {
	if (LEN(ans) == N) {
		cout << ans;
		exit(0);
	}
	FOR(i, 1, 3) {
		ans.push_back(i + '0');
		bool flag = false;
		for (int len = 1; len * 2 <= LEN(ans); len++) {
			string a = ans.substr(LEN(ans) - len * 2, len);
			string b = ans.substr(LEN(ans) - len, len);
			if (a == b) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			Func();
		}
		ans.pop_back();
	}
}

int main() {
	FASTIO;
	cin >> N;
	Func();

	return 0;
}