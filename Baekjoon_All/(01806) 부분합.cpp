#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[100001];

int main() {
	FASTIO;
	int N, S;
	int start, end;
	int sum = 0;
	int ans = 100001;
	cin >> N >> S;
	FOR(i, 1, N)
		cin >> arr[i];
	start = 1, end = 1;
	sum = arr[1];
	while (end <= N) {
		if (sum >= S) {
			ans = min(ans, end - start + 1);
			if (start == end) {
				start++;
				end++;
				sum = arr[start];
			}
			else {
				sum -= arr[start];
				start++;
			}
		}
		else if (sum < S) {
			end++;
			sum += arr[end];
		}
	}
	if (ans == 100001)
		cout << 0;
	else
		cout << ans;

	return 0;
}