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
	double x;
	cout << fixed << setprecision(2);
	while (cin >> x) {
		if (x == 0) break;
		if (x == 1) {
			cout << (double)5;
		}
		else if (x > 1) {
			cout << (pow(x, 5) - 1) / (x - 1);
		}
		else if (x < 1) {
			cout << (1 - pow(x, 5)) / (1 - x);
		}
		cout << "\n";
	}

	return 0;
}