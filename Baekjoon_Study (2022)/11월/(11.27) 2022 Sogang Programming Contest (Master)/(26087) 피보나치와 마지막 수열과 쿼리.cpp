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
#define MAX 1000001
#define MOD 1000000007

vector<pii> query(MAX);
vector<int> fib(MAX);
vector<int> nums(MAX, 0);
vector<int> jumping(MAX, -1);

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	fib[0] = 1;
	fib[1] = 1;
	FOR(i, 2, N) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	}
	FOR(i, 0, Q - 1) {
		cin >> query[i].first >> query[i].second;
	}

	ROF(i, Q - 1, 0) {
		int start = query[i].first;
		int end = query[i].second;
		int idx = start;
		while (idx <= query[i].second) {
			if (nums[idx] == 0) {
				nums[idx] = fib[idx - start + 1];
				jumping[idx] = end + 1;
				idx++;
			}
			else if (nums[idx] != 0) {
				idx = jumping[idx];
			}
		}
	}

	FOR(i, 1, N) {
		cout << nums[i] << " ";
	}

	return 0;
}