#include <bits/stdc++.h>
using namespace std;

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
	int S, T;
	cin >> S >> T;

	int sum = 0;
	FOR(i, 1, T) {
		int tmp = T / i - (S - 1) / i;
		if (i % 2 == 1) sum -= tmp;
		else if (i % 2 == 0) sum += tmp;
	}
	cout << sum;

	return 0;
}