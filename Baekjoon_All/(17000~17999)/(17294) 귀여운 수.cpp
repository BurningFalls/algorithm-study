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
	ll K;
	cin >> K;
	vector<int> v;
	while (K) {
		v.push_back(K % 10);
		K /= 10;
	}
	bool flag = true;
	if (LEN(v) >= 2) {
		int d = v[1] - v[0];
		FOR(i, 2, LEN(v) - 1) {
			if (v[i] - v[i - 1] != d) {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	}
	else if (!flag) {
		cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
	}

	return 0;
}