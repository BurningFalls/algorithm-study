#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[100001];

int main() {
	FASTIO;
	int N;
	ll X;
	ll sum = 0;
	cin >> N >> X;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum <= X) {
		cout << 1;
		return 0;
	}
	int cnt = sum / X;
	if (sum % X != 0)
		cnt++;
	int left = cnt, right = N;
	int ans = 100001;
	while(left <= right) {
		int mid = (left + right) / 2;
		priority_queue<ll> pq;
		FOR(i, 1, mid)
			pq.push(0);
		bool flag = true;
		FOR(i, 1, N) {
			ll tp = -pq.top();
			pq.pop();
			tp += arr[i];
			if (tp > X) {
				flag = false;
				break;
			}
			pq.push(-tp);
		}
		if (flag) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;

	return 0;
}