#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cutting[50010] = { 0, };
int cnt[50010] = { 0, };
int right_cnt[50010] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int s, e;
		cin >> s >> e;
		FOR(j, s, e - 1)
			cutting[j] += 1;
		FOR(j, s, e)
			cnt[j] += 1;
		right_cnt[e] += 1;
	}
	int sum = 0;
	int left = 1;
	int right = 7 * N;
	int start = 0, end = 0;
	FOR(i, left, right)
		sum += cnt[i];
	int max_sum = 0;
	while (right <= 50006) {
		if (sum > max_sum) {
			max_sum = sum;
			start = left;
			end = right;
		}
		sum -= cnt[left];
		left++;
		right++;
		sum += cnt[right];
	}
	int ans = 0;
	FOR(i, start, end) {
		ans += right_cnt[i];
		if ((i - start) % 7 == 6)
			ans += cutting[i];
	}
	cout << ans;


	return 0;
}