#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000001];
int cnt[11] = { 0, };

int maxi() {
	int idx = 10;
	while (cnt[idx] == 0)
		idx--;
	return idx;
}

int mini() {
	int idx = 1;
	while (cnt[idx] == 0)
		idx++;
	return idx;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int left = 1, right = 1;
	int ans = 1;
	cnt[arr[1]]++;
	while (++right <= N) {
		cnt[arr[right]]++;
		if (maxi() - mini() > 2) {
			while (maxi() - mini() > 2) {
				cnt[arr[left]]--;
				left++;
			}
		}
		ans = max(ans, right - left + 1);
	}
	cout << ans;

	return 0;
}