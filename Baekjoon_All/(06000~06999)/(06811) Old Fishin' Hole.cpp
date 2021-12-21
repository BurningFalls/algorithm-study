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
	int a, b, c, sum;
	cin >> a >> b >> c >> sum;
	int cnt = 0;
	FOR(i, 0, sum) {
		FOR(j, 0, sum) {
			FOR(k, 0, sum) {
				if (i + j + k == 0) continue;
				if (a * i + b * j + c * k <= sum) {
					cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel\n";
					cnt++;
				}
			}
		}
	}


	cout << "Number of ways to catch fish: " << cnt;


	return 0;
}