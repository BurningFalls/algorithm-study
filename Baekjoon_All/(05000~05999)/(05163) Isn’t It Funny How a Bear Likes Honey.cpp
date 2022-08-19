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
#define PI 3.14159265358979

int main() {
	FASTIO;
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		int N; double w;
		cin >> N >> w;
		double sum = 0;
		FOR(i, 1, N) {
			double x;
			cin >> x;
			sum += 4 * PI * x * x * x / 3;
		}
		sum /= 1000;
		cout << "Data Set " << tc << ":\n";
		cout << (w <= sum ? "Yes" : "No") << "\n\n";
	}

	return 0;
}