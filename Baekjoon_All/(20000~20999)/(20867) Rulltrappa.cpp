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
	double M, S, G;
	double A, B;
	double L, R;
	cin >> M >> S >> G;
	cin >> A >> B;
	cin >> L >> R;
	double t1 = L / A + M / G;
	double t2 = R / B + M / S;
	
	cout << (t1 > t2 ? "latmask" : "friskus");

	return 0;
}