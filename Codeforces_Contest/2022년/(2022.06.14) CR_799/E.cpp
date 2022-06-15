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
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, S;
		cin >> N >> S;
		vector<int> A(N);
		int total = 0;
		FOR(i, 0, N - 1) {
			cin >> A[i];
			total += A[i];
		}
		if (total < S) {
			cout << "-1\n";
			continue;
		}
		int left = 0;
		int cnt = (A[left] == 1);
		int right = left;
		while (cnt <= S) {
			right++;
			if (right >= N) break;
			cnt += (A[right] == 1);
		}
		right--;
		int mini = N - (right - left + 1);
		while (right < N - 1) {
			right++;
			while (right < N - 1 && A[right + 1] != 1) {
				right++;
			}
			while (left < N && A[left] != 1) {
				left++;
			}
			left++;
			mini = min(mini, N - (right - left + 1));
		}
		cout << mini << "\n";

	}

	return 0;
}