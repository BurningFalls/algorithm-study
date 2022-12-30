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
	map<int, int> mp;
	mp[1] = 1; mp[2] = 101;
	mp[3] = 10101; mp[4] = 1010101;
	FOR(t, 1, N) {
		int a, b, num;
		int asum = 0, bsum = 0;
		cin >> a;
		FOR(i, 0, a - 1) {
			cin >> num;
			asum += mp[num];
		}
		cin >> b;
		FOR(i, 0, b - 1) {
			cin >> num;
			bsum += mp[num];
		}
		if (asum > bsum) cout << 'A';
		else if (asum < bsum) cout << 'B';
		else if (asum == bsum) cout << 'D';
		cout << "\n";
	}

	return 0;
}