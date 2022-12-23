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
	vector<int> B(N + 1);
	vector<int> nums(N + 1, 0);
	FOR(i, 1, N) {
		cin >> B[i];
	}

	ROF(i, N, 1) {
		int idx = 0;
		FOR(j, 1, N) {
			if (nums[j] == 1) continue;
			idx++;
			B[idx] = (B[idx] ^ j);
		}
		nums[B[i]] = 1;
	}
	

	FOR(i, 1, N) {
		cout << B[i] << " ";
	}

	return 0;
}