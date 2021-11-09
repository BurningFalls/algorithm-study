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
	vector<int> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	int left = 0, right = N - 1;
	int ans = INF;
	while (left < right && left < N && right >= 0) {
		if (abs(ans) > abs(v[left] + v[right])) {
			ans = v[left] + v[right];
		}
		if (v[left] + v[right] > 0) {
			right--;
		}
		else if (v[left] + v[right] == 0) {
			break;
		}
		else if (v[left] + v[right] < 0) {
			left++;
		}
	}
	cout << ans;

	return 0;
}