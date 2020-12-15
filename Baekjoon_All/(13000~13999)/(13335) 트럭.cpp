#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];
queue<int> q;

int main() {
	FASTIO;
	int N, W, L;
	cin >> N >> W >> L;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int sum = 0;
	int ans = 0;
	FOR(i, 1, N) {
		while (true) {
			if (q.size() == W) {
				sum -= q.front();
				q.pop();
			}
			if (sum + arr[i] <= L)
				break;
			q.push(0);
			ans++;
		}
		q.push(arr[i]);
		sum += arr[i];
		ans++;
	}
	ans += W;
	cout << ans;

	return 0;
}