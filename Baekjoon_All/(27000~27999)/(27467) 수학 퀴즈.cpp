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
	double p = 0, q = 0;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		if (num % 3 == 0) {
			q += 1;
		}
		else if (num % 3 == 1) {
			p += 1;
		}
		else if (num % 3 == 2) {
			p -= 1;
			q -= 1;
		}
	}
	cout << fixed << setprecision(9);
	cout << p << " " << q;

	return 0;
}