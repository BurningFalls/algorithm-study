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
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int prev = 2;
	int cur = 0;
	int sum = 0;
	FOR(i, 0, N - 1) {
		if (sum == 0 || A[i - 1] != A[i]) {
			cur = 2;
		}
		else {
			cur = prev * 2;
		}
		sum += cur;
		if (sum >= 100) {
			sum = 0;
		}
		prev = cur;
	}
	cout << sum;

	return 0;
}