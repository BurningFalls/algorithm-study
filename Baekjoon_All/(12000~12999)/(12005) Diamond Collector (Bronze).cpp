#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int left = 1, right = 1;
	int cnt = 1;
	int max_cnt = 1;
	while (right <= N) {
		if (arr[right] - arr[left] <= K) {
			max_cnt = max(max_cnt, cnt);
			right++;
			cnt++;
		}
		else if (arr[right] - arr[left] > K) {
			left++;
			cnt--;
		}
	}
	cout << max_cnt;

	return 0;
}