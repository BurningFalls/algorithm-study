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
	int A, B, C = 0;
	cin >> A >> B;
	FOR(i, 0, 9) {
		bool f1 = (A & (1 << i));
		bool f2 = (B & (1 << i));
		if ((f1 ^ f2) == 1) {
			C += (1 << i);
		}
	}
	cout << C;

	return 0;
}