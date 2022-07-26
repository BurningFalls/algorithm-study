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
	FOR(i, 1, N) {
		string num;
		double a, b, c;
		cin >> num >> a >> b >> c;
		double sum = a + b + c;
		cout << num << " " << sum << " ";
		cout << (sum >= 55 && a >= 35 * 0.3 && b >= 25 * 0.3 && c >= 40 * 0.3 ? "PASS" : "FAIL") << "\n";
	}

	return 0;
}