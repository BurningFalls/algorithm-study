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
	int N, L;
	cin >> N >> L;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int sum = 0;
	int cnt = 0;
	FOR(i, 0, L - 1) {
		cnt += (129 <= sum && sum <= 138);
		sum += A[i];
	}
	int left = 0, right = L - 1;
	while (right < N) {
		cnt += (129 <= sum && sum <= 138);
		sum -= A[left];
		left++;
		right++;
		if (right >= N) break;
		sum += A[right];
	}
	cout << cnt;

	return 0;
}