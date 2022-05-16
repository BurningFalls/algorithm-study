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
	int N;
	cin >> N;
	vector<ll> d(N);
	ll sum = 0;
	FOR(i, 0, N - 1) {
		cin >> d[i];
		sum += d[i];
	}

	if (N == 1 && d[0] == 1) {
		cout << "Happy";
		return 0;
	}

	bool flag = true;
	FOR(i, 0, N - 1) {
		if (sum - d[i] < d[i]) {
			flag = false;
		}
	}

	cout << (flag ? "Happy" : "Unhappy");

	return 0;
}