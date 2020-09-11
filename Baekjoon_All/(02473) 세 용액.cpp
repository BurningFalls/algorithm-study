#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll arr[5001];
int ans[3];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	ll minimum = 3100000000;
	bool zero_flag = false;
	sort(arr + 1, arr + N + 1);
	FOR(i, 1, N) {
		int start = 1, end = N;
		while (start != end) {
			if (i == start) {
				start++;
				continue;
			}
			else if (i == end) {
				end--;
				continue;
			}
			ll temp = arr[start] + arr[end] + arr[i];
			if (llabs(temp) < minimum) {
				minimum = llabs(temp);
				ans[0] = arr[start];
				ans[1] = arr[end];
				ans[2] = arr[i];
			}
			if (temp == 0) {
				zero_flag = true;
				break;
			}
			else if (temp > 0)
				end--;
			else if (temp < 0)
				start++;
		}
		if (zero_flag)
			break;
	}
	sort(ans, ans + 3);
	FOR(i, 0, 2)
		cout << ans[i] << " ";

	return 0;
}