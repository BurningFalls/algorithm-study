#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[200001];
int cnt[100001] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	int left = 1, right = 1;
	int max_length = 1;
	cnt[arr[1]]++;
	while (++right <= N) {
		if (cnt[arr[right]] == K) {
			while (arr[left] != arr[right]) {
				cnt[arr[left]]--;
				left++;
			}
			left++;
		}
		else {
			cnt[arr[right]]++;
		}
		max_length = max(max_length, right - left + 1);
	}
	cout << max_length;

	return 0;
}