#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

long double Dist[100001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		int P;
		cin >> P;
		long double max_dist = 0;
		FOR(j, 1, P) {
			long double x, y;
			cin >> x >> y;
			max_dist = max(max_dist, x * x + y * y);
		}
		Dist[i] = max_dist;
	}
	sort(Dist + 1, Dist + N + 1);
	cout << fixed << setprecision(2);
	cout << Dist[K];


	return 0;
}