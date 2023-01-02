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
	vector<int> sum(5001, 0);
	vector<int> check(5001, 0);
	FOR(i, 1, 5000) {
		int sqrtn = sqrt(i);
		bool flag = true;
		FOR(j, 1, sqrtn) {
			if (i % j == 0) {
				sum[i] += j;
				if (sum[j] > j) {
					flag = false;
				}
				if (j != 1 && j * j != i) {
					sum[i] += (i / j);
					if (sum[i / j] > i / j) {
						flag = false;
					}
				}
			}
		}
		check[i] = flag;
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (sum[N] > N && check[N]) {
			cout << "Good Bye";
		}
		else {
			cout << "BOJ 2022";
		}
		cout << "\n";
	}

	return 0;
}