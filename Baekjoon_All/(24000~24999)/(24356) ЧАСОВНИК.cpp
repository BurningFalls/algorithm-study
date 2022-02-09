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
	int t1, t2, m1, m2;
	cin >> t1 >> m1 >> t2 >> m2;
	int tmp1 = t1 * 60 + m1;
	int tmp2 = t2 * 60 + m2;
	int timing = (tmp2 - tmp1 + 1440) % 1440;
	cout << timing << " " << timing / 30;

	return 0;
}