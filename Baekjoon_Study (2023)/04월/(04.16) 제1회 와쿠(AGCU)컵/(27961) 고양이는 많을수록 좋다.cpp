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
	ll N;
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	bool flag = false;
	while (N > 1) {
		if (N % 2 == 1) {
			flag = true;
		}
		N /= 2;
		cnt++;
	}
	cout << (!flag ? cnt + 1 : cnt + 2);

	return 0;
}