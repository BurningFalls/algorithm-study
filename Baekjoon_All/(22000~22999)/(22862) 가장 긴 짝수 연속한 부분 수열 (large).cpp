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
	int N, K;
	cin >> N >> K;
	vector<int> v(N + 2);
	v[0] = 1, v[N + 1] = 1;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		v[i] = (num % 2);
	}

	int left = 0, right = 0;
	int cnt = 0;
	while (right < N + 2 && cnt < K + 2) {
		cnt += (v[right] % 2 == 1);
		right++;
	}

	int maxi = right - left - cnt;
	while (right < N + 2) {
		while (right < N + 2 && v[right] % 2 == 0) {
			right++;
		}
		left++;
		while (left < N + 2 && v[left] % 2 == 0) {
			left++;
		}
		maxi = max(maxi, right - left + 1 - (K + 2));
		right++;
	}
	cout << maxi;

	return 0;
}