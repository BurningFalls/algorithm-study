#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string S;
	int sum[101];
	sum[0] = 0;
	cin >> S;
	int Slen = S.size();
	FOR(i, 0, Slen - 1) {
		sum[i + 1] = sum[i] + (S[i] - '0');
	}
	int ans = 0;
	for (int len = 2; len <= Slen; len += 2) {
		int left = 1, right = len;
		while (right <= Slen) {
			int left_sum = sum[left + len / 2 - 1] - sum[left - 1];
			int right_sum = sum[right] - sum[right - len / 2];
			if (left_sum == right_sum) {
				ans = len;
				break;
			}
			left++; right++;
		}
	}
	cout << ans;


	return 0;
}