#include <bits/stdc++.h>
using namespace std;

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
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int left = 0, right = 0;
	int length = A[0];
	int ans = 0;
	while (right < N) {
		if (length > M) {
			length -= A[left];
			left++;
			if (left > right) {
				right++;
				if (right < N) {
					length += A[right];
				}
			}
		}
		else if (length <= M) {
			ans = max(ans, length);
			right++;
			if (right < N) {
				length += A[right];
			}
		}
	}
	cout << ans;

	return 0;
}