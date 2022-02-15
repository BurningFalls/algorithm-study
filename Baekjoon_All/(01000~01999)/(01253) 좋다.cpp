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
	for (int& x : v) {
		cin >> x;
	}
	sort(ALL(v));

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int left = 0, right = N - 1;
		while (left < right) {
			if (left == i || v[i] > v[left] + v[right]) {
				left++;
			}
			else if (right == i || v[i] < v[left] + v[right]) {
				right--;
			}
			else {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}