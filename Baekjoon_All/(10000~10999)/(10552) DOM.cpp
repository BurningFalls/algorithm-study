#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Ch[100001] = { 0, };
bool use[100001] = { 0, };

int main() {
	FASTIO;
	int N, M, P;
	cin >> N >> M >> P;
	use[P] = 1;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		if (Ch[b] == 0)
			Ch[b] = a;
	}
	int cnt = 0;
	bool flag = true;
	while(true) {
		if (Ch[P] != 0) {
			if (use[Ch[P]]) {
				flag = false;
				break;
			}
			else {
				P = Ch[P];
				use[P] = 1;
				cnt++;
			}
		}
		else if (Ch[P] == 0) {
			break;
		}
	}
	cout << (flag ? cnt : -1);

	return 0;
}