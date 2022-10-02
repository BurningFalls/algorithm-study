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
	int N, P;
	cin >> N >> P;
	int a = max(0, P - 500);
	int b = max(0, P * 9 / 10);
	int c = max(0, P - 2000);
	int d = max(0, P * 3 / 4);
	if (N >= 20) {
		cout << min({ a, b, c, d });
	}
	else if (N >= 15) {
		cout << min({ a, b, c });
	}
	else if (N >= 10) {
		cout << min({ a, b });
	}
	else if (N >= 5) {
		cout << a;
	}
	else {
		cout << P;
	}


	return 0;
}