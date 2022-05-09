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
	int a, b, d;
	cin >> a >> b >> d;
	int cnt = 0;
	int timing = 0;
	int pos = 0;
	while (true) {
		if (cnt % 2 == 0) {
			if (pos + a >= d) {
				timing += d - pos;
				pos = d;
				break;
			}
			else {
				timing += a;
				pos += a;
			}
		}
		else if (cnt % 2 == 1) {
			timing += b;
		}
		cnt = (cnt + 1) % 2;
	}
	cnt = 0;
	while (true) {
		if (cnt % 2 == 0) {
			if (pos - b <= 0) {
				timing += pos;
				pos = 0;
				break;
			}
			else {
				pos -= b;
				timing += b;
			}
		}
		else if (cnt % 2 == 1) {
			timing += a;
		}
		cnt = (cnt + 1) % 2;
	}

	cout << timing;

	return 0;
}