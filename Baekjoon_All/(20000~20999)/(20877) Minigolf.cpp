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
	int sum1 = 0, sum2 = 0;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (i % 2 == 0) {
			sum2 += 3;
		}
		else if (i % 2 == 1) {
			sum2 += 2;
		}
		sum1 += min(7, num);
	}
	cout << sum1 - sum2;


	return 0;
}