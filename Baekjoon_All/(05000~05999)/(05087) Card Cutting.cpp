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
	while (true) {
		char c;
		cin >> c;
		if (c == '#') break;
		int cnt1 = 0, cnt2 = 0;
		cnt1 += (c == 'A' || (c - '0') % 2 == 1);
		cnt2 += ((c - '0') % 2 == 0);
		while (true) {
			cin >> c;
			if (c == '*') break;
			cnt1 += (c == 'A' || (c - '0') % 2 == 1);
			cnt2 += ((c - '0') % 2 == 0);
		}
		if (cnt1 > cnt2) {
			cout << "Cheryl";
		}
		else if (cnt1 == cnt2) {
			cout << "Draw";
		}
		else if (cnt1 < cnt2) {
			cout << "Tania";
		}
		cout << "\n";
	}

	return 0;
}