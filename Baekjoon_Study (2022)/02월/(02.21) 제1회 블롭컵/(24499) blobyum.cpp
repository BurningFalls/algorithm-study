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
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int left = 0, right = K - 1;
	int sum = 0;
	FOR(i, 0, K - 1) {
		sum += A[i];
	}
	int maxi = sum;
	while (true) {
		sum -= A[left];
		left = (left + 1) % N;
		right = (right + 1) % N;
		sum += A[right];
		if (left == 0) break;
		maxi = max(maxi, sum);
	}
	cout << maxi;

	return 0;
}