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
	int sum1 = 0;
	int sum2 = 0;
	bool flag;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
		sum1 += A[i];
	}
	FOR(i, 0, N - 1) {
		cin >> flag;
		if (!flag) {
			sum2 += A[i];
		}
	}
	cout << sum1 << "\n" << sum2;


	return 0;
}